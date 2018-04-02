#include <iostream>

#include <stack>
#include "mem.h"

// debug
std::initializer_list<int> IL = {1,2,3};

Mem<int> stackSharedMem{IL};

int main() {
    try {
    std::cout << "Hi\n";
    std::stack<Mem<int>::value_pointer> s {};
    
    // ---- JUST A UNIT TEST ------------
    auto p = stackSharedMem.allocate();
    while(p) {
        s.push(p);
        std::cout << p->data << "\n";
        p = stackSharedMem.allocate();
    }
    
    while(s.size()) {
        stackSharedMem.deallocate(s.top(), std::size_t{});
        s.pop();
    }
        Node<int> n;
        stackSharedMem.deallocate(&n, std::size_t{});
    // ----------------------------------
    }
    catch(std::exception& e) {
        std::cout << "exception occured:: " << e.what() << std::endl;
    }
    
}
