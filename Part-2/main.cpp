#include<iostream>
#include "BPTree.h"




int main() {
	BPTree<int, int>* tree = new BPTree<int, int>;
	/*std::cout << "Test";
	BPLeaf<int, int> b;
	BPNode<int, int>* a = &b;
	a->add(10,10);*/
	tree->insert(5, 5);
	tree->insert(15, 15);
	std::cout<<tree->find(5);
	std::cout << tree->find(15);
	//int b[] = { 10,25,36,48 };
	//std::cout<<binaryle(b, 4, 13);
}