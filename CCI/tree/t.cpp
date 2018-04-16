#include <iostream>
#include <sstream>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <memory>

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

template <typename U, typename F>
void traverseTreeS(treeNode<U>* nodePtr, F nodeProc) {		
	
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
void traverseTreeSRec(treeNode<U>* nodePtr, F nodeProc) {
	if(nodePtr) {
		traverseTreeSRec(nodePtr->left, nodeProc);
		traverseTreeSRec(nodePtr->right, nodeProc);
		nodeProc(nodePtr);
	}
}

template <typename U, typename F>
void _traverseTreeQ(treeNode<U>* nodePtr, F nodeProc) {		
	
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
void traverseTreeQ(treeNode<U>* nodePtr, F nodeProc) {
	if(nodePtr) {
		nodeProc(nodePtr->data);
		_traverseTreeQ(nodePtr->left, nodeProc);
		_traverseTreeQ(nodePtr->right, nodeProc);
		
	}
}

template <typename U, typename F>
void traverseTreeQRec(treeNode<U>* nodePtr, F nodeProc) {
	if(nodePtr) {
		nodeProc(nodePtr->data);
		traverseTreeQRec(nodePtr->left, nodeProc);
		traverseTreeQRec(nodePtr->right, nodeProc);
		
	}
}

int main() {

	std::cout << "tree traverse\n";
	std::vector<std::unique_ptr<treeNode<char>>> v;
	createTree(v);
	treeNode<char>* node = v.front().get();
	
	std::cout << "Stack \n";
	traverseTreeS(node, [](char n) { std::cout << n << " " ;});
	std::cout << "\n";
	
	std::cout << "Stack recurse\n";
	traverseTreeS(node, [](char n) { std::cout << n << " " ;});
	std::cout << "\n";
	
	std::cout << "queue \n";
	traverseTreeQ(node, [](char n) { std::cout << n << " " ;});
	std::cout << "\n";	
	
	std::cout << "queue  recurse\n";
	traverseTreeQRec(node, [](char n) { std::cout << n << " " ;});
	std::cout << "\n";
}

