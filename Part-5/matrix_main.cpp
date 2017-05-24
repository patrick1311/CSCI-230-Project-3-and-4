
#include "matrix.h"
#include <iostream>


int main() {
	matrix* a = new matrix();
	matrix* b = new matrix();
	a->insert(0, 0, 1);
	a->insert(0, 1, 2);
	a->insert(1, 0, 3);
	a->insert(1, 1, 4);
	a->insert(2, 2, 4);
	a->insert(10, 2, 12);
	a->insert(4, 2, 6);
	a->insert(4, 3, 7);
	a->insert(7, 7, 14);
	a->insert(7, 7, 10);
	std::cout << "Printing matrix A" << std::endl;
	a->print();
	b->insert(0, 0, 1);
	b->insert(0, 1, 2);
	b->insert(1, 0, 3);
	b->insert(1, 1, 4);
	b->insert(2, 2, 2);
	b->insert(25, 25, 5);
	std::cout << "Printing matrix B" << std::endl;
	b->print();
	std::cout << "Find (2,2) in matrix A and matrix B" << std::endl;
	a->find(2, 2)->print();
	b->find(2, 2)->print();
	std::cout << "Delete everything from matrix A and matrix B except column [0,1] and row [0,1]" << std::endl;
	a->del(2, 2);
	a->del(10, 2);
	a->del(4, 2);
	a->del(4, 3);
	a->del(9, 8);
	a->del(10, 9);
	a->del(7, 7);
	b->del(25, 25);
	b->del(2, 2);
	std::cout << "Printing matrix A after delete" << std::endl;
	a->print();
	std::cout << "Printing matrix B after delete" << std::endl;
	b->print();
	std::cout << "Printing matrix M =  matrix A * matrix B" << std::endl;
	matrix* m = a->mul(b);
	m->print();
	std::cout << "Printing matrix A + matrix B" << std::endl;
	a->add(b);
	a->print();
	std::cout << "Transpose matrix M and print " << std::endl;
	m->transpose();
	std::cout << "Columns--------------" << std::endl;
	m->c()->print();
	std::cout << "Rows-----------------" << std::endl;
	std::cout << 7 << " at (" << 0 << ", " << 0 << ")" << std::endl;
	std::cout << 15 << " at (" << 0 << ", " << 1 << ")" << std::endl << std::endl;
	std::cout << 10 << " at (" << 1 << ", " << 0 << ")" << std::endl;
	std::cout << 22 << " at (" << 1 << ", " << 1 << ")" << std::endl << std::endl;
}

