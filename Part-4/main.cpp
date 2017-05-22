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
    
    sList.insert(5, 23);
    sList.insert(1, 90);
    sList.insert(2, 2312);
    cout << "Size of sList is " << sList.size() << endl;
    sList.print();
    cout << sList.find(90) << endl;
    
    sList.clear();
    cout << "\nAfter clear size is " << sList.size() << endl;
    sList.print();
    
    sList.insert(10, 2);
    sList.print();
    return 0;
}
