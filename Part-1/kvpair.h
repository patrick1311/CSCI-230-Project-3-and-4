template <typename Key, typename E>
class KVpair {
private:
	Key k;
	E e;
	bool empty = true;
public:
	// Constructors
	KVpair() {}
	KVpair(Key kval, E eval)
	{
		k = kval; e = eval;
		empty = false;
	}
	KVpair(const KVpair& o)  // Copy constructor
	{
		k = o.k; e = o.e; empty = o.empty;
	}

	void operator =(const KVpair& o) // Assignment operator
	{
		k = o.k; e = o.e; empty = o.empty;
	}

	// Data member access functions
	Key key() { return k; }
	void setKey(Key ink) { k = ink; }
	E value() { return e; }
	bool isEmpty() 
	{
		return empty;
	}

};
