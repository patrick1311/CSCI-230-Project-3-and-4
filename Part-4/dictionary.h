//
//  dictionary.h
//  SkipList
//
//  Created by Patrick Quach on 5/18/17.
//  Copyright © 2017 Patrick Quach. All rights reserved.
//

#ifndef dictionary_h
#define dictionary_h

// The Dictionary abstract class.
template <typename Key, typename E>
class  Dictionary {
private:
    void operator =(const Dictionary&) {}
    Dictionary(const Dictionary&) {}
public:
    Dictionary() {}          // Default constructor
    virtual ~Dictionary() {} // Base destructor
    // Reinitialize dictionary
    virtual void clear() = 0;
    // Insert a record
    // k: The key for the record being inserted.
    // e: The record being inserted.
    virtual void insert(const Key& k, const E& e) = 0;
    // Remove and return a record.
    // k: The key of the record to be removed.
    // Return: A maching record. If multiple records match
    // "k", remove an arbitrary one. Return NULL if no record
    // with key "k" exists.
    virtual E remove(const Key& k) = 0;
    // Return: A record matching "k" (NULL if none exists).
    // If multiple records match, return an arbitrary one.
    // k: The key of the record to find
    virtual E find(const Key& k) const = 0;
    // Return the number of records in the dictionary.
    virtual int size() = 0;
};

#endif /* dictionary_h */
