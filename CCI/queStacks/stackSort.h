//
// Created by Dmitriy Andreev on 4/5/2018.
//

#ifndef QUESTACKS_STACKSORT_H
#define QUESTACKS_STACKSORT_H

#include <stack>
#include "utils.h"

template <typename T>
void popNpush(std::stack<T>& l, std::stack<T>& r) {
    if(! l.empty()) {
        T tmp(std::move(l.top()));
        l.pop();
        r.emplace(std::move(tmp));
    }
}

template <typename T, typename Cmp = std::less<T>>
void stackSort(std::stack<T>& s, Cmp comp = Cmp{}) {
    auto elCount = s.size();

    if(elCount < 2) {
        return;
    }

    std::stack<T> tmpS {};

    while(elCount) {

        T tmp(std::move(s.top()));
        s.pop();

        auto c = elCount - 1;
        while (c--) {
            if (comp(s.top(), tmp)) {
                tmpS.emplace(std::move(tmp));
                tmp = std::move(s.top());
                s.pop();
            } else {
                popNpush(s, tmpS);
            }
        }
        tmpS.emplace(std::move(tmp));

        while (!tmpS.empty()) {
            popNpush(tmpS, s);
        }
        --elCount;
    }
}
#endif //QUESTACKS_STACKSORT_H
