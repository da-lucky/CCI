#include "graph.hpp"
#include <iostream>

AdjacentNodesVectorT adjVector;
std::vector<NodeColor> props;

void createGraphAdjList() {
	
	for(auto i = 0; i < NUM_NODES_IN_GRAPH; i++) {
		adjVector.push_back(std::list<std::size_t>{});
	}
	
	adjVector[0].push_back(1);
	adjVector[0].push_back(3);
	
	adjVector[1].push_back(4);
	
	adjVector[2].push_back(5);
	adjVector[2].push_back(4);
	
	adjVector[3].push_back(1);
	
	adjVector[4].push_back(3);
	
	adjVector[5].push_back(5);
}

void initAdjCont() {
	
	props.clear();	
	for(auto i = 0; i < NUM_NODES_IN_GRAPH; i++) {
		props.push_back(NodeColor::WHITE);
	}
}

void DFSvisit(std::size_t idx) {
	
	std::cout << "Visit node " << idx << "\n";
	
	props[idx] = NodeColor::GRAY;	
	
	for(auto It = adjVector[idx].begin(); It != adjVector[idx].end() ; ++It) {
		
		if(NodeColor::WHITE == props[*It]) {
			DFSvisit(*It);
		}	
	}
	
	props[idx] = NodeColor::BLACK;
}

void DFS() {

	initAdjCont();
	
	for(std::size_t i = 0; i < adjVector.size(); i++) {
		if(NodeColor::WHITE == props[i]) {
			DFSvisit(i);
		}
	}
}