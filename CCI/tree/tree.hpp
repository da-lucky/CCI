#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <sstream>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <memory>
#include <cstdlib>

#include "treeNode.h"

//--------------------- Symmetric traverse -----------------------------
template <typename U, typename F>
void traverseTreeSymmetric(treeNode<U>* nodePtr, F nodeProc) {		
	
	std::stack<treeNode<U>*> node_s {};
	std::size_t max = 0, min = 0, cnt = 0;
		
	while (true) {
		if(nodePtr) {
			node_s.push(nodePtr);	
			nodePtr = nodePtr->left;
			
		} else {
			if(node_s.empty()) {
				return;
			}
			nodeProc(node_s.top()->data);
			nodePtr = node_s.top()->right;
			node_s.pop();			
		}
	}
}

template <typename U, typename F>
void traverseTreeSymmetricRec(treeNode<U>* nodePtr, F nodeProc) {
	if(nodePtr) {
		traverseTreeSymmetricRec(nodePtr->left, nodeProc);
		nodeProc(nodePtr->data);
		traverseTreeSymmetricRec(nodePtr->right, nodeProc);
		
	}
}

//--------------------- Pre order traverse -----------------------------
template <typename U, typename F>
void _traverseTreePreO(treeNode<U>* nodePtr, F nodeProc) {		
	
	std::stack<treeNode<U>*> node_s {};	
		
	while (true) {
		if(nodePtr) {
			node_s.push(nodePtr);
			nodeProc(node_s.top()->data);
			nodePtr = nodePtr->left;
		} else {
			if(node_s.empty()) {
				return;
			}
			nodePtr = node_s.top()->right;
			node_s.pop();
		}
	}
}

template <typename U, typename F>
void traverseTreePreO(treeNode<U>* nodePtr, F nodeProc) {
	if(nodePtr) {
		nodeProc(nodePtr->data);
		_traverseTreePreO(nodePtr->left, nodeProc);
		_traverseTreePreO(nodePtr->right, nodeProc);
		
	}
}

template <typename U, typename F>
void traverseTreePreORec(treeNode<U>* nodePtr, F nodeProc) {
	
	if(nodePtr) {		
		nodeProc(nodePtr->data);
		traverseTreePreORec(nodePtr->left, nodeProc);
		traverseTreePreORec(nodePtr->right, nodeProc);
	}
}

//--------------------- Post order traverse -----------------------------
template <typename U, typename F>
void traverseTreePostORec(treeNode<U>* nodePtr, F nodeProc) {
	
	if(nodePtr) {		
		traverseTreePostORec (nodePtr->left, nodeProc);
		traverseTreePostORec (nodePtr->right, nodeProc);
		nodeProc(nodePtr->data);
	}
}

//----------------- check for tree balancing -----------------------
template <typename U>
bool tBalaced(treeNode<U>* nodePtr) {
	bool status = true;
	
	treeBalanceCheck(nodePtr, status);
	
	return status;
}

template <typename U>
int treeBalanceCheck(treeNode<U>* nodePtr, bool& status) {
	if(nodePtr && status) {
		auto l = treeBalanceCheck(nodePtr->left, status) + 1;
		auto r = treeBalanceCheck(nodePtr->right, status) + 1;
			
		if(std::abs(l - r) > 1) { 
			std::cout << "\ntree is not balanced:node " << nodePtr->data << " lh:rh " << (l - 1) << ":" << (r - 1) << " \n";		
			status = false;
		}
		
		return (l > r) ? l : r;
	} else {
		return 0;
	}
}


//----------------- check for BST -----------------------
template <typename U>
bool BSTCheck(treeNode<U>* nodePtr, const U& min, const U& max) {
    if(nullptr == nodePtr) {
        return false;
    }
    
    if (nodePtr->data < min || nodePtr->data >= max) {
        {
            //DEBUG
            if(nodePtr->data < min) {
                std::cout << "current node " << nodePtr->data << " less than min " << min << "\n";
            }
            if(nodePtr->data >= max) {
                std::cout << "current node " << nodePtr->data << " greater than max " << max << "\n";
            }
        }
        return false;
    }
    
    if ( !BSTCheck(nodePtr->left, min, nodePtr->data) ||
        !BSTCheck(nodePtr->right, nodePtr->data, max)) {
        return false;
    }
    return true;
}

#endif
