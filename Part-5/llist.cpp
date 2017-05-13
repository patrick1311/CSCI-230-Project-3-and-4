//
//  llist.cpp
//  Sparse Matrix
//
//  Created by Patrick Quach on 5/11/17.
//  Copyright © 2017 Patrick Quach. All rights reserved.
//

#include <stdio.h>
#include "list.h"
#include "assert.h"

// Singly linked list node
template <typename E> class Link {
public:
    E element;      // Value for this node
    Link *down;   //Pointer to bottom node
    Link *next;        // Pointer to next node in list
    // Constructors
    Link(const E& elemval, Link* nextval =NULL, Link* downval =NULL)
    { element = elemval;  next = nextval; down = downval; }
    Link(Link* nextval =NULL, Link* downval =NULL) { next = nextval; down = downval; }
};


// This is the declaration for LList. It is split into two parts
// because it is too big to fit on one book page
// Linked list implementation
template <typename E> class LList: public List<E> {
private:
    Link<E>* head;       // Pointer to list header
    Link<E>* tail;       // Pointer to last element
    Link<E>* curr;       // Access to current element
    int cnt;    	       // Size of list
    
    void init() {        // Intialization helper method
        curr = tail = head = new Link<E>;
        cnt = 0;
    }
    
    void removeall() {   // Return link nodes to free store
        while(head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
    
public:
    LList(int size=defaultSize) { init(); }    // Constructor
    ~LList() { removeall(); }                   // Destructor
    void print() const;                // Print list contents
    void clear() { removeall(); init(); }       // Clear list
    
    // Insert "it" at current position
    void insert(const E& it) {
        curr->next = new Link<E>(it, curr->next);
        if (tail == curr) tail = curr->next;  // New tail
        cnt++;
    }
    
    void appendNext(const E& it) { // Append "it" to list
        tail = tail->next = new Link<E>(it, NULL, NULL);
        cnt++;
    }
    
    void appendDown(const E& it) { // Append "it" to list
        tail = tail->down = new Link<E>(it, NULL, NULL);
        cnt++;
    }
    
    // Remove and return current element
    E remove() {
        assert(curr->next != NULL);
        E it = curr->next->element;      // Remember value
        Link<E>* ltemp = curr->next;     // Remember link node
        if (tail == curr->next) tail = curr; // Reset tail
        curr->next = curr->next->next;   // Remove from list
        delete ltemp;                    // Reclaim space
        cnt--;			     // Decrement the count
        return it;
    }
    
    void moveToStart() // Place curr at list start
    { curr = head; }
    
    void moveToEnd()   // Place curr at list end
    { curr = tail; }
    
    // Move curr one step left; no change if already at front
    void prev() {
        if (curr == head) return;       // No previous element
        Link<E>* temp = head;
        // March down list until we find the previous element
        while (temp->next!=curr) temp=temp->next;
        curr = temp;
    }
    
    // Move curr one step right; no change if already at end
    void next()
    { if (curr != tail) curr = curr->next; }
    
    void down()
    { if (curr != tail) curr = curr->down; }
    
    int length() const  { return cnt; } // Return length
    
    // Return the position of the current element
    int currPos() const {
        Link<E>* temp = head;
        int i;
        for (i=0; curr != temp; i++)
            temp = temp->next;
        return i;
    }
    
    // Move down list to "pos" position
    void moveToPos(int pos) {
        assert ((pos>=0)&&(pos<=cnt));
        curr = head;
        for(int i=0; i<pos; i++) curr = curr->next;
    }
    
    const E& getNextValue() const { // Return current element
        assert(curr->next != NULL);
        return curr->next->element;
    }
    
    const E& getDownValue() const { // Return current element
        assert(curr->down != NULL);
        return curr->down->element;
    }
    
    //reset current pointer
    void reset() {
        curr = head;
    }
};