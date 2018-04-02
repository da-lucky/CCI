#include <iostream>

#include <stack>
#include "mem.h"

// debug
std::initializer_list<int> IL = {1,2,3};

Mem<int> stackSharedMem{IL};

int main() {
    std::cout << "Hi\n";
    std::stack<Mem<int>::value_pointer> s {};
    
    // ---- JUST A UNIT TEST ------------
    auto p = stackSharedMem.popFree();
    while(p) {
        s.push(p);
        std::cout << p->data << "\n";
        p = stackSharedMem.popFree();
    }
    
    while(s.size()) {
        stackSharedMem.pushFree(s.top());
        s.pop();
    }
    // ----------------------------------
    
    
}
