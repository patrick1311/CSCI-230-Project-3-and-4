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


template <typename E> class Matrix {
private:
    MNode<E>* node=NULL;
    LList<E> row;
    LList<E> column;
public:
    Matrix() {
        for(int i = 0; i < 7; i++)
            column.append(i);
      //  for(int i = 0; i < 5; i++)
            row.append(1);
        row.append(3);
        row.append(9);
        row.append(11);
    }
    
    void print() {
        column.moveToStart();
        row.moveToStart();
        
        for(int i = 0; i < column.length(); i++) {
            printf("%4d", column.getValue());
            column.next();
        }

        cout << endl;
        
        for(int i = 0; i < row.length(); i++) {
            cout << row.getValue() << endl;
            row.next();
        }
    }
   
    void insert(E e, int r, int c) {
        column.moveToStart();
        row.moveToStart();
        
        bool rowFound = findPos(row, r);
        bool colFound = findPos(column, c);
        
        cout << "test row " << rowFound << endl;
        cout << "test col " << colFound << endl;
        
        //insert row & column if not present
        if(!rowFound)
            row.add(r); //add new row
        
        if(!colFound)
            column.add(c);  //add new column

        //add matrix node
        
        node = row.getPtr();
        if(node == NULL) {
            node = new MNode<E>;
            node->element = e;
            node->row = r;
            node->column = c;
        }
        
        
        if(rowFound && colFound)
            cout << "add matrix node" << endl;
        else
            cout <<"need to insert" << endl;
    }
    
    bool findPos(LList<E> &list, int pos) {
        for(int i = 0; i < list.length(); i++) {
            
            if (list.getValue() == pos) {
                return true;
            }

            list.next();
        }

        return false;
    }
};