//
//  main.cpp
//  Sparse Matrix
//
//  Created by Patrick Quach on 5/11/17.
//  Copyright © 2017 Patrick Quach. All rights reserved.
//

#include <iostream>
#include "list.h"
#include "olmatrix.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    std::cout << "Hello, World!\n";
    
    Matrix<int> m(10);
    cout<<" ";
    m.printCol();
    cout<<endl;
    m.printRow();
    return 0;
}
