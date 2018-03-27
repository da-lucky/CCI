//
//  permutate.h
//  lists
//
//  Created by Дмитрий Андреев on 23.03.2018.
//

#ifndef permutate_h
#define permutate_h

#include <iterator> 
#include "node.h"

template <typename T>
void permutate(Node<T>& listStart, const T& p) {
    
}

template <typename FwIt, typename Predicate>
void permutate(FwIt b, FwIt e, Predicate p, std::forward_iterator_tag) {
    std::cout << "fwd iter\n";
    auto first = b;
    while(first != e) {
        if(! p(*first)) {
            break;
        }
        ++first;
    }

    if(first == e) {
        return;
    }

    for (auto i = std::next(first); i != e; ++i) {
        if(p(*i)) {
            std::iter_swap(first, i);
            ++first;
        }
    }
}

template <typename BIt, typename Predicate>
void permutate(BIt b, BIt e, Predicate p, std::bidirectional_iterator_tag) {
    std::cout << "bidir iter\n";
    auto left = b;
    auto right = e;

    while(left != right) {
        if(p(*left)) {
            ++left;
        } else {
            while(left != --right && !p(*right)) {};
            std::iter_swap(left, right);
        }
    }
}

template <typename It, typename Predicate>
void permutate(It b, It e, Predicate p) {
    permutate(b, e, p, typename std::iterator_traits<It>::iterator_category());
}

#endif /* permutate_h */
