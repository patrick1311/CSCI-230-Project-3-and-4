#include <iostream>
#include <string>
#include "hashDictionary.h"

void printMenu();
void Option(hashDictionary<std::string, int>* );

int main() {
	int n;
	std::cout << "Enter hash table size: ";
	std::cin >> n;
	hashDictionary<std::string, int>* hash = new hashDictionary<std::string, int>(n);
	Option(hash);
}

void Option(hashDictionary<std::string, int>* hash) {
	int option = 1;
	std::string key;
	int value;
	while (option != 0) {
		printMenu();
		std::cin >> option;
		switch (option) {
		case 1:
			std::cout << "Enter Key: ";
			std::cin >> key;
			std::cout << "Enter value: ";
			std::cin >> value;
			hash->insert(key, value);
			break;
		case 2:
			std::cout << "Enter Key: ";
			std::cin >> key;
			value = hash->remove(key);
			if (value != NULL) {
				std::cout << "Record removed: " << value << std::endl;
			} 
			break;
		case 3:
			hash->print();
			break;
		case 4:
			hash->clear();
			break;
		default:
			break;
		}
	}
}
void printMenu() {
	std::cout << "Output options (1 - insert, 2 - remove, 3 - print, 4 - clear)" << std::endl;
}
