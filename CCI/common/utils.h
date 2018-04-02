#ifndef COMMON_UTILS_H
#define COMMON_UTILS_H

#include <iostream>
#include <sstream>

template <typename Cont>
void printCont(const Cont& c) {
    std::stringstream ss;
    for (const auto& item: c) {
        ss << item << " ";
    }
    std::cout <<ss.str() << std::endl;
}

template <typename It>
void connectListElements(It b, It e) {
    if(b != e) {
        It p = b;
        while (++p != e) {
            conn(*b, *p);
            ++b;
        }
    }
}

#endif //COMMON_UTILS_H
