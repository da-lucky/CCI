// created by D. Andreev
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include "node.h"
#include "listLoopFinder.h"
#include "polindrome.h"
#include "utils.h"
#include "listUtils.h"
#include "permutate.h"

int main() {
    // my comment
    // from MAC
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
    {
        std::cout << "POLINDROME\n\n";
        std::vector <Node<int>> poliv = {1/*, 2, 3, 3, 2, 1*/};
        connectListElements(poliv.begin(), poliv.end());
        std::cout << std::boolalpha;
        std::cout << "is polyndrome " << poly(poliv.front()) << "\n";
    }
    // permutate
    {
        std::cout << "PERMUTATE\n\n";
        std::forward_list<int> fl = {4, 3, 2, 7, 5, 0, 11, 1};
        printCont(fl);
        //partition(fl.begin(), fl.end(), [](const auto& item){ return (item < 3);});
        permutate(fl.begin(), fl.end(), [](const auto &item) { return (item < 3); });
        printCont(fl);

        std::list<int> l = {4, 3, 2, 7, 5, 0, 11, 1};
        printCont(l);
        //partition(l.begin(), l.end(), [](const auto& item){ return (item < 3);});
        permutate(l.begin(), (l.end() ), [](const auto &item) { return (item < 3); });
        printCont(l);

        std::cout << "\n";
        std::vector <Node<int>> poliv = {8, 6, 10, 1};
        connectListElements(poliv.begin(), poliv.end());
        printCont(poliv.front());

        auto rez = permutate(&poliv.front(), 3);
        printCont(*rez);
    }
    //
    {

    }
    return 0;
}
