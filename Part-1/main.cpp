#include <iostream>
#include <string>
#include "hashDictionary.h"


int main()
{
	hashDictionary<std::string, int> a(100);
	a.insert("apple", 2);
	a.insert("apple", 3);
	a.insert("apple1", 4);
	std::cout << a.find("apple1") << std::endl;
	a.print();
	a.remove("apple1");
	a.print();
	a.clear();
	a.print();
	hashDictionary<std::string, int> b(100);
}

