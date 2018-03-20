#ifndef CLION_LIST_H
#define CLION_LIST_H

#include <iostream>

template<typename T>
struct Node {
    T data;
    Node* next;

    Node() : data{T()}, next{nullptr} {}
    Node(const T& d) : data{d}, next{nullptr} { std::cout << "Node const T& c-tor\n"; }
    Node(T&& d) : data{std::move(d)}, next{nullptr} { std::cout << "Node move c-tor\n";  }

    Node(const T& d, Node* ptr) : data{d}, next{ptr} { /*std::cout << "Node const T& c-tor\n";*/ }
};

template<typename T>
std::ostream& operator<< (std::ostream& s, const Node<T>& n) {
    s << n.data << "::" << n.next << "\n";
    return s;
}

#endif //CLION_LIST_H
