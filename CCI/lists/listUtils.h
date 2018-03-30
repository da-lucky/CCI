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

template <typename T>
void printCont(const Node<T>& n) {
    std::stringstream ss;
    auto r = &n;
    while(r) {
        ss <<  r->data << " ";
        r = r->next;
    }
    std::cout <<ss.str() << std::endl;
}
#endif //LISTS_LISTUTILS_H
