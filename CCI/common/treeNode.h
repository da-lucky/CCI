#ifndef TREENODE_H
#define TREENODE_H

template<typename T>
struct treeNode {
	T data;
	treeNode* left;
	treeNode* right;
};

#endif