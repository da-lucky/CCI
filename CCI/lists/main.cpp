#include <iostream>
#include <sstream>
#include <vector>
#include "node.h"
#include "listLoopFinder.h"
#include "polindrome.h"
#include "utils.h"
#include "listUtils.h"

int main() {
    // my comment
    std::vector<Node<int>> v = {1, 2, 3, 4, 5, 6};

    printCont(v);
    connectListElements(v.begin(), v.end());

    v.back().next = &v[1];

    printCont(v);

    auto ptr = getListLoopStart(&v[0]);

    if(ptr) {
        std::cout << "loop start is " << ptr->data << std::endl;
    } else {
        std::cout << "loop not found in list" << std::endl;
    }

    // is polindrome
    std::vector<Node<int>> poliv = {1, 2, 3, 4, 5, 6};
    connectListElements(poliv.begin(), poliv.end());

    return 0;
}