#include <iostream>
#include <deque>
#include "graph.hpp"

// global graph nodes container
CGraphNodes<std::size_t, std::vector> g_graphNodes ;

void populateGrapNodesContainer() {
    for(auto i = 0; i < NUM_NODES_IN_GRAPH; ++i) {
        g_graphNodes.addNode(i);
    }
    std::cout << "Size of g_graphNodes " << g_graphNodes.size() << "\n";    
}

void prepareGraphAdjList() {
	
    g_graphNodes.addLink(0,1);
    g_graphNodes.addLink(0,3);

    g_graphNodes.addLink(1,4);

    g_graphNodes.addLink(2,5);
    g_graphNodes.addLink(2,4);

    g_graphNodes.addLink(3,1);
    g_graphNodes.addLink(4,3);
    g_graphNodes.addLink(5,5);

    for(auto i = 0; i < g_graphNodes.size(); i++) {
        g_graphNodes.printNodeLinks(i);
    }
}

void DFS() {

    g_graphNodes.DFS();
}
