//
//  permutate.h
//  lists
//
//  Created by Дмитрий Андреев on 23.03.2018.
//

#ifndef permutate_h
#define permutate_h

#include "node.h"

template <typename T>
void permutate(Node<T>& listStart, const T& p) {
    
}

template <typename FwIt>
void permutate(FwIt b, FwIt e, typename std::iterator_traits<FwIt>::value_type p) {
    if (b == e) {
        return;
    }
    
}

//template <typename FwIt, typename T>
//void permutate(FwIt b, FwIt e, T p) {
//    std::cout << "permutate ver 2\n";
//}


#endif /* permutate_h */
