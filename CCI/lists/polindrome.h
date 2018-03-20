#ifndef LISTS_POLINDROME_H
#define LISTS_POLINDROME_H

#include <stack>
#include "node.h"

template <typename T>
bool poly(const Node<T>& node) {
    const auto slow = &node;
    const auto fast = &node;
    std::stack<const Node<T>*> st {};

    if(nullptr == node.next) {
        return false;
    }

    while(fast && fast->next) {
        st.push(slow);
        fast = fast->next->next;
        slow = slow->next;
    }

    // in case there're only 2 elements in the list
    if(nullptr == slow->next) {
        return (node.data == slow->data);
    }

    // even number of elements
    if(nullptr == fast) {
        slow = slow->next;
    }

    while(slow) {
        if(*slow->data != st.top()) {
            return false;
        }
        st.pop();
        slow = slow->next;
    }
    return true;
}



#endif //LISTS_POLINDROME_H
