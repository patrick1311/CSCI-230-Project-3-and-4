//
//  skiplist.h
//  SkipList
//
//  Created by Patrick Quach on 5/18/17.
//  Copyright © 2017 Patrick Quach. All rights reserved.
//

#ifndef skiplist_h
#define skiplist_h
#include <stdlib.h>
#include <iostream>
#include "dictionary.h"
using namespace std;


#define MAXLEVEL 2

template <typename Key, typename E>
class SkipNode {
public:
    int nodeLevel;
    Key k;
    E it;
    SkipNode** forward;
    
    //set up header node
    SkipNode() {
        nodeLevel = MAXLEVEL;
        forward = new SkipNode*[MAXLEVEL + 1];
        for(int i = 0; i <= MAXLEVEL; i++)
            forward[i] = NULL;
    }
    
    SkipNode(Key key, E e, int level) {
        k = key;
        it = e;
        nodeLevel = level;
        forward = new SkipNode*[level + 1];
        for(int i = 0; i < level; i++)
            forward[i] = NULL;
    }
    
    ~SkipNode() {
        delete [] forward;
    }
};

template <typename Key, typename E>
class SkipList: public Dictionary<Key, E> {
private:
    SkipNode<Key,E>* head;
    int level;
    int count;

public:
    
    SkipList() {
        head = new SkipNode<Key, E>;
        level = MAXLEVEL;
        count = 0;
    }
    
    //cannot exceed MAXLEVEL
    void AdjustHead(int &lvl) {
        lvl = MAXLEVEL;
    }
    
    E find(const Key& k) const {
        SkipNode<Key,E> *x = head;         // Dummy header node
        for (int i=level; i>=0; i--)
            while ((x->forward[i] != NULL) &&
                   (k > x->forward[i]->k))
                x = x->forward[i];
        x = x->forward[0];  // Move to actual record, if it exists
        if ((x != NULL) && (k == x->k)) return x->it;
        return NULL;
    }

    void insert(const Key& k, const E& it) {
        int i;
        SkipNode<Key,E> *x = head;   // Start at header node
        int newLevel = randomLevel(); // Select level for new node
        if (newLevel > level) {     // New node is deepest in list
            AdjustHead(newLevel);     // Add null pointers to header
            level = newLevel;
        }
        SkipNode<Key,E>* update[level+1]; // Track level ends
        for(i=level; i>=0; i--) {   // Search for insert position
            while((x->forward[i] != NULL) && (x->forward[i]->k < k))
                x = x->forward[i];
            update[i] = x;           // Keep track of end at level i
        }
        x = new SkipNode<Key,E>(k, it, newLevel);   // New node
        for (i=0; i<=newLevel; i++) {          // Splice into list
            x->forward[i] = update[i]->forward[i]; // Where x points
            update[i]->forward[i] = x;           // What points to x
        }
        count++;
    }
    
    
    E remove(const Key& K) {
        
        return false;
    }
    
    void clear() {
        //set all head pointers to NULL
        for(int i = 0; i <= MAXLEVEL; i++) {
            head->forward[i] = NULL;
        }
        count = 0;
    }
    
    void print() {
        SkipNode<Key, E>* temp = head;
        for(int i = 0; i < count; i++) {
            if(temp->forward[0]->k != NULL)
                cout << "Key: " << temp->forward[0]->k
                    << " - Item: " << temp->forward[0]->it
                    << " - Level: " << temp->forward[0]->nodeLevel << endl;
            
            temp = temp->forward[0];
        }
    }
    
    int size() {
        return count;
    }

    //generate random level from 0 to MAXLEVEL
    int randomLevel() {
        int level = rand() % (MAXLEVEL + 1);
        return level;
    }
};
#endif /* skiplist_h */
