#ifndef LISTS_LISTUTILS_H
#define LISTS_LISTUTILS_H

#include <sstream>

template <typename T>
void conn(Node<T>& first, Node<T>& second) {
    first.next = &second;
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

#endif //LISTS_LISTUTILS_H
