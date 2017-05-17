//
//  mnode.cpp
//  Sparse Matrix
//
//  Created by Patrick Quach on 5/15/17.
//  Copyright © 2017 Patrick Quach. All rights reserved.
//

#include <stdio.h>

//Matrix node
template <typename E> class MNode {
public:
    E element;
    int row;
    int column;
    MNode<E>* right;
    MNode<E>* left;
    MNode<E>* top;
    MNode<E>* bottom;
    
    MNode() {
        right = NULL;
        left = NULL;
        top = NULL;
        bottom = NULL;
    }
    
    MNode (const E& e, MNode *r, MNode *l, MNode *t, MNode *b, int rowPos, int colPos) {
        element = e;
        right = r;
        left = l;
        top = t;
        bottom = b;
        row = rowPos;
        column = colPos;
    }
    
    void setValue() {}
};

template <typename E> class MatrixList {
private:
    
    
public:
    
};