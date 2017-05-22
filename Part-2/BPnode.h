// Abstract class definition for B+-trees
template <typename Key, typename E>class BPNode {
public:
	BPNode* leftptr;  BPNode* rightptr; // Links to siblings
	virtual ~BPNode() {} // Base destructor
	virtual BPNode<Key, E>* add(Key k, E e) { return this; };
	virtual Key* keys() = 0;    // Return array of keys
	virtual bool isLeaf() const = 0;  // True if node is a leaf
	virtual bool isFull() const = 0;  // True if node is full
	virtual int numrecs() const = 0;  // Current num of records
};





