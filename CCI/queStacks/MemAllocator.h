//
//  MemAllocator.h
//  queStack
//
//  Created by Дмитрий Андреев on 02.04.2018.
//

#ifndef MemAllocator_h
#define MemAllocator_h

#include "mem.h"

template<typename T>
struct MemAllocator {
    Mem<T>& m_mem;
    
    MemAllocator(Mem<T>& a): m_mem(a) {    }
    
    typename Mem<T>::value_pointer allocate(std::size_t n) {
        return m_mem.allocate();
    }
    
    void deallocate(typename Mem<T>::value_pointer p, std::size_t) {
        m_mem.deallocate(p, std::size_t {});
    }
};

#endif /* MemAllocator_h */
