#include <iostream>
#include <sstream>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <memory>
#include <cstdlib>

template<typename T>
struct treeNode {
	T data;
	treeNode* left;
	treeNode* right;
};

void createTree(std::vector<std::unique_ptr<treeNode<char>>>& v) {
		
	for(auto i = 'A'; i < 'N'; i++ ) {
		std::unique_ptr<treeNode<char>> p {new treeNode<char>};
		p->data = i;
		p->left = nullptr;
		p->right = nullptr;
		
		v.push_back(std::move(p));
	}
	
	/*A*/v[0]->left = v[1].get(); /*B*/
	/*B*/v[1]->left = v[2].get(); /*C*/
	/*B*/v[1]->right = v[3].get(); /*D*/
	
	/*A*/v[0]->right = v[4].get();/*E*/
	/*E*/v[4]->right = v[5].get();/*F*/
	/*F*/v[5]->left = v[6].get();/*G*/
	/*F*/v[5]->right = v[7].get();/*H*/
	/*H*/v[7]->left = v[8].get();/*I*/
	/*H*/v[7]->right = v[9].get();/*J*/
	
	/*D*/v[3]->left = v[10].get();/*K*/
	/*D*/v[3]->right = v[11].get();/*L*/
	
	
	/*C*/v[2]->right = v[12].get();/*M*/
}

//--------------------- Post order traverse -----------------------------
template <typename U, typename F>
void traverseTreePostO(treeNode<U>* nodePtr, F nodeProc) {		
	
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
void traverseTreePostORec(treeNode<U>* nodePtr, F nodeProc) {
	if(nodePtr) {
		traverseTreePostORec(nodePtr->left, nodeProc);
		nodeProc(nodePtr->data);
		traverseTreePostORec(nodePtr->right, nodeProc);
		
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

//----------------- check for tree balancing -----------------------
template <typename U>
bool tBalaced(treeNode<U>* nodePtr) {
	bool status = true;
	
	treeBalanceCheck(nodePtr, status);
	
	return status;
}

template <typename U>
int treeBalanceCheck(treeNode<U>* nodePtr, bool& status) {
	if(nodePtr) {	
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

int main() {

	std::vector<std::unique_ptr<treeNode<char>>> v;
	createTree(v);
	treeNode<char>* node = v.front().get();
	
	std::cout << "Post Order \n";
	traverseTreePostO(node, [](char n) { std::cout << n << " " ;});
	std::cout << "\n";
	
	std::cout << "Post Order recurse\n";
	traverseTreePostORec(node, [](char n) { std::cout << n << " " ;});
	std::cout << "\n";
	
	std::cout << "Pre Order \n";
	traverseTreePreO(node, [](char n) { std::cout << n << " " ;});
	std::cout << "\n";	
	
	std::cout << "Pre Order  recurse\n";	
	traverseTreePreORec(node, [](char n) { std::cout << n << " " ;});
	std::cout << "\n";
	
	std::cout << std::boolalpha;
	std::cout << "is tree balanced: " << tBalaced(node) << "\n";	
}

