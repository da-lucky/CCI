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

#endif //COMMON_UTILS_H
