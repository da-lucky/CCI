#include <iostream>
#include <initializer_list>
#include <stack>
#include "mem.h"
#include "NodeStack.h"
#include "MemAllocator.h"
#include "stackSort.h"

// debug
//std::initializer_list<int> IL = {1,2,3, 4, 5, 6, 7, 8, 9, 10};

Mem<int> stackSharedMem{/*IL*/};
MemAllocator<int> memAllocator(stackSharedMem);


int main() {
    try {

        {
            std::cout << "Test 3.1\n";
            NodeStack<int, MemAllocator<int>> nodeStack1{memAllocator};
            NodeStack<int, MemAllocator<int>> nodeStack2{memAllocator};

            auto n = 2;
            while (n--) {
                auto i = 6;
                while (i) {
                    nodeStack1.push(i);
                    if (i & 1) {
                        nodeStack2.push(i * (-1));
                    }
                    --i;
                }
                nodeStack1.printoutEls();
                nodeStack2.printoutEls();

                std::cout << "top is " << nodeStack1.top() << "\n";
                nodeStack1.pop();
                nodeStack1.pop();
                std::cout << "top is " << nodeStack1.top() << "\n";

                nodeStack1.push(500);
                nodeStack2.push(-123);

                nodeStack1.printoutEls();
                nodeStack2.printoutEls();

                nodeStack1.clean();
                nodeStack2.clean();
                std::cout << "\n\n";
            }
        }
        {
            std::cout << "Test 2\n";

            std::stack<int> stack2sort {};

            for(auto& i: std::initializer_list<int>{9,1,7,2,10,3,8}) {
                stack2sort.push(i);
            }

            printCont(stack2sort);
            stackSort(stack2sort,std::greater<int> {});

            printCont(stack2sort);
        }
    }
    catch(std::exception& e) {
        std::cout << "exception occured:: " << e.what() << std::endl;
    }
}
