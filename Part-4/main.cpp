//
//  main.cpp
//  SkipList
//
//  Created by Patrick Quach on 5/16/17.
//  Copyright © 2017 Patrick Quach. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "skiplist.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    srand((unsigned) time(0));
    SkipList<int, int> sList;
    
    //testing insert() and size() function
    sList.insert(5, 23);
    sList.insert(1, 90);
    sList.insert(2, 45);
    cout << "Size of sList is " << sList.size() << endl;
    sList.print();
    
    //testing find() function
    cout << "\nSearching for key 5: " << sList.find(5) << endl;
    
    //testing clear() function
    sList.clear();
    cout << "\nAfter clear size is " << sList.size() << endl;
    sList.print();
    
    //testing remove() function
    sList.insert(1, 90);
    sList.insert(2, 52);
    sList.insert(5, 11);
    sList.insert(6, 100);
    sList.insert(3, 41);
    sList.insert(4, 31);
    sList.insert(12, 24);
    
    sList.print();
    cout << "\nRemoving INVALID data: " << sList.remove(10) << endl;
    sList.print();
    cout << "\nRemoving VALID data: " << sList.remove(5) << endl;
    sList.print();
    cout << "\nRemoving VALID data: " << sList.remove(2) << endl;
    sList.print();
    cout << "\nRemoving INVALID data: " << sList.remove(90) << endl;
    sList.print();
    return 0;
}
