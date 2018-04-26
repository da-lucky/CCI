#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <queue>
#include <exception>
#include <array>
#include <sstream>
#include <list>
#include "treeNode.h"

constexpr std::size_t NUM_NODES_IN_GRAPH = 6;

using NodeTime_T = uint32_t;

enum class NodeColor {
	WHITE,
	GRAY,
	BLACK
};

struct SNodeProperties{
    NodeColor c;
    NodeTime_T d;
    NodeTime_T f;
};

template<class T, template<class...>class  Cont>
class CGraphNodes{
    Cont<T> m_nodesContainer;
    Cont<std::list<std::size_t>> m_links;
    Cont<SNodeProperties> m_props;
    NodeTime_T m_time = 0;

    void resetProps() {
        m_time = 0;
        for(auto& i:m_props) {
            i.c = NodeColor::WHITE;
            i.d = 0;
            i.f = 0;
        }
    }

    void DFS_visit(std::size_t idx) {
        
        m_props[idx].c = NodeColor::GRAY;
        m_props[idx].d = m_time++;

        std::cout << "\tEnter node " << idx << " d = " << m_props[idx].d << "\n";
                
        for(auto It = std::begin(m_links[idx]); It != std::end(m_links[idx]); ++It) {
            if(NodeColor::WHITE == m_props[*It].c) {
                DFS_visit(*It);
            }
        };
        m_props[idx].f = m_time++;
        m_props[idx].c = NodeColor::BLACK;

        std::cout << "\tExit node " << idx << " d = " << m_props[idx].f << "\n";
    }

public:
    CGraphNodes() = default;
    ~CGraphNodes() = default;

    std::size_t size() const {
        return m_nodesContainer.size();
    }

    template <typename U>
    void addNode(U&& n) {
        m_nodesContainer.insert(std::end(m_nodesContainer), std::forward<U>(n));
        m_links.push_back(std::list<std::size_t> {});
        m_props.push_back({NodeColor::WHITE, 0, 0});
    }

    void clear() {
        m_nodesContainer.clear();
    }

    T& operator[](std::size_t i) {
        return m_nodesContainer[i];
    }

    const T& operator[](std::size_t i) const {
        return m_nodesContainer[i];
    }

    T& at(std::size_t i) {
        if(i < size()) {
            return m_nodesContainer[i];
        }
        std::stringstream ss;
        ss << "idx " << std::to_string(i) << " > than container size" << std::to_string(size()) << "\n";
            throw std::out_of_range(ss.str());
    }

    const T& at(std::size_t i) const {
        if(i < size()) {
            return m_nodesContainer[i];
        }
        std::stringstream ss;
        ss << "idx " << std::to_string(i) << " > than container size" << std::to_string(size()) << "\n";
            throw std::out_of_range(ss.str());
    }

    void addLink(std::size_t l, std::size_t r) {
        if (l < size() && r << size()) {
            m_links[l].push_back(r);
        } else {
            std::stringstream ss;
            ss << "left node idx " << std::to_string(l) << " or righ idx " << std::to_string(r) << " greater than size of cont " << size();
            std::cerr << ss.str() << "\n";
        }
    }

    void printNodeLinks(std::size_t idx) {
        if(idx < size()) {
            std::stringstream ss;
            ss << "node " << idx <<" links:{ ";
            for(const auto& e: m_links[idx]) {
                ss << std::to_string(e) << " ";
            }
            std::cout << ss.str() << "}\n";
        } else {
            std::stringstream ss;
            ss << "idx " << std::to_string(idx) << " greater than size of cont " << size();
            std::cerr << ss.str() << "\n";
        }
    }

    void DFS() {
        std::cout << "DFS search\n";

        resetProps();        
        
        for(auto i = 0; i < size(); ++i) {
            if(NodeColor::WHITE == m_props[i].c) {
                DFS_visit(i);
            }
        }
    }

    void BFS(std::size_t start = 0) {
        std::cout << "BFS search\n";

        resetProps();
    
        std::queue<std::size_t> q;
        m_props[start].c = NodeColor::GRAY;
        m_props[start].d = 0;

        q.push(start);

        while(q.size()) {
            auto e = q.front();

            std::cout << "\tnode " << e << " d = " << m_props[e].d << "\n";

            for(auto& i: m_links[e]) {
                if(NodeColor::WHITE == m_props[i].c) {
                    m_props[i].c = NodeColor::GRAY;
                    m_props[i].d = m_props[e].d + 1;
                    q.push(i);
                }
            }

            m_props[e].c = NodeColor::BLACK;            
            q.pop();
        }
    }
};

void prepareGraphAdjList();
void populateGrapNodesContainer();
void DFS();
void BFS();

#endif
