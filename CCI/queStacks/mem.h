//
//  Header.h
//  queStack
//
//  Created by Дмитрий Андреев on 01.04.2018.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <array>
#include "node.h"
#include "utils.h"

template<typename T>
class Mem {
public:
    static constexpr std::size_t MEM_SIZE = 3;
    using value_type = Node<T>;
    using value_pointer = Node<T>*;

private:
    std::array<Node<T>, MEM_SIZE> m_arr;
    value_pointer currFree;
    
private:
    void linkElements() {
        connectListElements(m_arr.begin(), m_arr.end());
        m_arr.back().next = nullptr;
    }
    
    void init() {
        linkElements();
        currFree = &m_arr[0];
    }
    
    bool ptrCorrect(value_pointer p) const {
        return ((nullptr == p) || (p >= &m_arr.front() && p <= &m_arr.back())) ? true : false ;
    }
    
public:
    
    Mem() {
        init();
    }
    
    Mem(const std::initializer_list<T>& l) {
        init();
        if(l.size() > m_arr.size()) {
            throw std::invalid_argument("number of elems in init list is lower than arr size");
        }
        auto lptr = l.begin();
        for(auto& i:m_arr) {
            i.data = *lptr;
            ++lptr;
        }
    }
    
    Mem(const Mem&) = delete;
    Mem& operator=(const Mem&) = delete;
    
    value_pointer popFree() {
        auto tmp = currFree;
        if(currFree) {
            currFree = currFree->next;
            tmp->next = nullptr;
        }
        return tmp;
    }
    
    void pushFree(value_pointer p) {
        if(ptrCorrect(p)) {
            if (nullptr == p) {
                return;
            }
            p->next = currFree;
            currFree = p;
            return;
        }
        throw std::invalid_argument("wrong pointer given");
    }
    
};

#endif /* Header_h */
