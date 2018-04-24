#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <array>
#include <list>
#include "treeNode.h"

constexpr std::size_t NUM_NODES_IN_GRAPH = 6;

using AdjacentNodesVectorT = std::vector<std::list<std::size_t>>;

enum class NodeColor {
	WHITE,
	GRAY,
	BLACK
};

void createGraphAdjList();
void DFS();

#endif