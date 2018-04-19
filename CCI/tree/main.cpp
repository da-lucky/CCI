#include "tree.hpp"

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

int main() {

	std::vector<std::unique_ptr<treeNode<char>>> v;
	createTree(v);
	treeNode<char>* node = v.front().get();
	
	std::cout << "Symmetric order\n";
	traverseTreeSymmetric(node, [](char n) { std::cout << n << " " ;});
	std::cout << "\n";
	
	std::cout << "Symmetric order recurse\n";
	traverseTreeSymmetricRec(node, [](char n) { std::cout << n << " " ;});
	std::cout << "\n";
	
	std::cout << "Pre Order \n";
	traverseTreePreO(node, [](char n) { std::cout << n << " " ;});
	std::cout << "\n";	
	
	std::cout << "Pre Order  recurse\n";	
	traverseTreePreORec(node, [](char n) { std::cout << n << " " ;});
	std::cout << "\n";
	
	std::cout << "Post Order  recurse\n";	
	traverseTreePostORec(node, [](char n) { std::cout << n << " " ;});
	std::cout << "\n";
	
	std::cout << std::boolalpha;
	/* Task 1 : checking whether tree is balanced */	
	std::cout << "\tis tree balanced: " << tBalaced(node) << "\n";
	
	/* Task 2 : checking whether tree Binary Search Tree */	
	std::cout << "\n\tis BST: " << isBST(node) << "\n";
}

