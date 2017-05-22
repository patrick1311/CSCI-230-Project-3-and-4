#include "BPnode.h"

const int maxrecs = 3;
const int maxpointers = 3;

int binaryle(int a[], int length, int k)
{
	int position = length - 1;
	for (int i = 0; i < length-1; i++)
	{
		if (k <= a[i])
		{
			position = i;
			break;
		}
	}
	return position;
}
// Implementation for leaf node
template <typename Key, typename E>
class BPLeaf : public BPNode<Key, E> {
private:
	Key theKeys[maxpointers];
	E theRecs[maxpointers];
	int currecs; // The number of records now

public:
	BPLeaf() { currecs = 0; }  // constructor
	~BPLeaf() {}
	bool isLeaf() const { return true; }
	bool isFull() const { return (currecs == maxrecs); }
	int numrecs() const { return currecs; }
	Key* keys() { return theKeys; }
	E recs(int which) const { return theRecs[which]; }

	BPNode<Key, E>* del(int which) { return this; }
	BPNode<Key, E>* add(Key k, E e)
	{
		int index = binaryle(theKeys, currecs + 1, k);
		//std::cout << index;
		for (int i = currecs; i > index; i--)  //shift all the keys and recs
		{
			theKeys[i] = theKeys[i - 1];
			theRecs[i] = theRecs[i - 1];
		}
			
		theKeys[index] = k;
		theRecs[index] = e;
		currecs++;
		if(isFull())
		{
			int half = currecs/2;
			BPInternal<Key, E>* root = new BPInternal<Key,E>();
			BPLeaf<Key, E>* rsib = new BPLeaf<Key,E>();
			rightptr = rsib;
			rsib->leftprt = this;
			for(int i = half; i < currecs; i++)
			{
				rsib->add(thekeys[i], therecs[i]);
				thekeys[i] == NULL;
			}
			currecs = half;
			return root;
		}
		return this;
	}

};

// Implementation for leaf node
template <typename Key, typename E>
class BPInternal : public BPNode<Key, E> {
private:
	Key* theKeys;
	BPNode<Key, E>* thePointers[maxpointers];
	int currecs; // The number of records now
public:
	BPInternal() {
		currecs = 0;
		theKeys = new Key[maxpointers];
	}
	bool isLeaf() const { return false; }
	bool isFull() const { return (currecs == maxpointers); }
	int numrecs() const { return currecs; }
	Key* keys() const { return theKeys; }
	BPNode<Key, E>* pointers(int which) const { return thePointers[which]; }

	// stubs
	BPInternal<Key, E>* add(Key k, BPInternal<Key, E>* ptr) 
	{ 
		currecs++;
		return NULL;
	}
	bool underflow(int which) { return false; }
};

