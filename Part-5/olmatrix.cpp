//
//  olmatrix.cpp
//  Sparse Matrix
//
//  Created by Patrick Quach on 5/11/17.
//  Copyright © 2017 Patrick Quach. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "llist.cpp"
using namespace std;

template <typename E> class MNode {
public:
    E element;
    int row;
    int column;
    MNode *right;
    MNode *left;
    MNode *top;
    MNode *bottom;
    MNode (const E& e, MNode *r, MNode *l, MNode *t, MNode *b, int rowPos, int colPos) {
        element = e;
        right = r;
        left = l;
        top = t;
        bottom = b;
        row = rowPos;
        column = colPos;
    }
};

template <typename E> class Matrix {
private:
    int size;
    LList<E> row;
    LList<E> column;
public:
    Matrix(int s) {
        size = s;
        //fill out the row & column index
        for(int i = 0; i < size; i++) {
            row.appendDown(i);
            column.appendNext(i);
        }
    }
   
    void printRow(){
        for(int i = 0; i < size; i++) {
            cout << row.getDownValue() << endl;
            row.down();
        }
        
        row.reset();
    }
    
    void printCol(){
        for(int i = 0; i < size; i++) {
            printf("%3d", column.getNextValue());
            column.next();
        }
        
        column.reset();
    }
    
    void insert(E e, int r, int c) {
        int counter = 0;
        
        //get to the correct row
        while (counter < r) {
            row.down();
        }
        
        if(row.next == NULL)
            row.next = new MNode<E>(e, NULL, NULL, NULL, NULL, r, c);
    }
   
};