//
//  NodeStack.h
//  queStack
//
//  Created by Дмитрий Андреев on 02.04.2018.
//

#ifndef NodeStack_h
#define NodeStack_h

#include <memory>
#include "mem.h"

template<typename T, typename Allocator = std::allocator<Node<T>>>
class NodeStack {
public:
    using value_type = T;
    using value_pointer = T*;
    using value_reference = T&;
    
private:
    Allocator m_alloc;
    Node<T>* m_top = nullptr;
    std::size_t m_numEls = 0;
    
public:
    
    NodeStack() = default;
    
    NodeStack(Allocator a) : m_alloc(a) {}
    
    std::size_t size() const {
        return m_numEls;
    }
    
    value_reference top() {
        if(! m_numEls) {
            throw std::runtime_error("Node stack is empty");
        }
        return m_top->data;
    }
    
    template<typename U>
    bool push(U&& v) {
        if(auto p = m_alloc.allocate(1)) {
            new (p) Node<T>(std::forward<U>(v));
            p->next = m_top;
            m_top = p;
            ++m_numEls;
            return p;
        }
        throw std::bad_alloc();
    }
    
    void pop() {
        if(m_top) {
            auto p = m_top;
            m_top = m_top->next;
            m_alloc.deallocate(p, std::size_t {});
            --m_numEls;
        }
    }
    
    void clean() {
        while(m_numEls) {
            pop();
        }
    }
    
    // debug
    void printoutEls() const {
        if (m_top) {
            printCont(*m_top);
        }
    }
    
};

#endif /* NodeStack_h */
