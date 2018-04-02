#ifndef CLION_LIST_H
#define CLION_LIST_H

#include <iostream>
#include <sstream>

template<typename T>
struct Node {
    T data;
    Node* next;

    Node() : data{T()}, next{nullptr} {}
    Node(const T& d) : data{d}, next{nullptr} { /*std::cout << "Node const T& c-tor\n";*/ }
    Node(T&& d) : data{std::move(d)}, next{nullptr} { /* std::cout << "Node move c-tor\n"; */ }

    Node(const T& d, Node* ptr) : data{d}, next{ptr} { /*std::cout << "Node const T& c-tor\n";*/ }
};

template<typename T>
std::ostream& operator<< (std::ostream& s, const Node<T>& n) {
    s << n.data << "::" << n.next << "\n";
    return s;
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

/* connector function template to use it in connect list items */
template <typename T>
void conn(Node<T>& first, Node<T>& second) {
    first.next = &second;
}

#endif //CLION_LIST_H
