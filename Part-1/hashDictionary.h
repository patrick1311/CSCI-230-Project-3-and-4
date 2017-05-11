#include "dictionary.h"
#include "kvpair.h"
#include <string>

/*
h(hashCode) = ((a * hashCode + b) mod p) mod N

Here, a, b, and p are positive integers, p is a large prime, and p >> N. Now, the number N of buckets doesn't need to be prime.

private static int hashCode(String key) {
int hashVal = 0;
for (int i = 0; i < key.buckets(); i++) {
hashVal = (127 * hashVal + key.charAt(i)) % 16908799;
}
return hashVal;
}
*/

template <typename Key, typename E>
class hashDictionary : public Dictionary<Key, E> {
private:
	KVpair<Key, E>* hashtable;
	int buckets;
	int records;
public:
	hashDictionary() {} // Default constructor
	hashDictionary(int n)
	{
		hashtable = new KVpair<Key, E>[n];
		records = 0;
		buckets = n;
	}

	~hashDictionary() { delete[] hashtable; } // Base destructor
											  // Reinitialize dictionary
	void clear()
	{
		for (int i = 0; i < buckets; i++)
		{
			hashtable[i] = KVpair<Key, E>();
		}
		records = 0;
	}
	// Insert a record
	// k: The key for the record being inserted.
	// e: The record being inserted.
	void insert(const Key& k, const E& e)
	{
		int num = hash(hashcode(k));
		while (!hashtable[num].isEmpty())
		{
			num++;
			num = num % buckets;
		}
		hashtable[num] = KVpair<Key, E>(k, e);
		records++;
	}
	// Remove and return a record.
	// k: The key of the record to be removed.
	// Return: A matching record. If multiple records match
	// "k", remove an arbitrary one. Return NULL if no record
	// with key "k" exists.
	E remove(const Key& k)
	{
		int num = hash(hashcode(k));
		int count = 0;
		while (hashtable[num].key() != k)
		{
			num++;
			count++;
			num = num % buckets;
			if (count == buckets)
			{
				std::cout << "Not found" << std::endl;
				return NULL;
			}
		}
		records--;
		E rec = hashtable[num].value();
		hashtable[num] = KVpair<Key, E>();
		return rec;
	}
	// Remove and return an arbitrary record from dictionary.
	// Return: The record removed, or NULL if none exists.
	E removeAny()
	{
		return 0;
	}
	// Return: A record matching "k" (NULL if none exists).
	// If multiple records match, return an arbitrary one.
	// k: The key of the record to find
	E find(const Key& k)
	{
		int num = hash(hashcode(k));
		int count = 0;
		while (hashtable[num].key() != k)
		{
			num++;
			count++;
			num = num % buckets;
			if (count == buckets)
			{
				std::cout << "Not found" << std::endl;
				return NULL;
			}
		}
		return hashtable[num].value();
	}
	// Return the number of records in the dictionary.
	int size()
	{
		return records;
	}

	int hashcode(std::string key)
	{
		int hashVal = 0;
		for (int i = 0; i < key.length(); i++) {
			hashVal = (127 * hashVal + key.at(i)) % 16908799;
		}
		return hashVal;
	}

	int hash(int hashCode)
	{
		int a = 2;
		int b = 10;
		int p = 541;
		return ((a * hashCode + b) % p) % buckets;
	}

	void print()
	{
		for (int i = 0; i < buckets; i++)
		{
			if (!hashtable[i].isEmpty())
			{
				std::cout << "Index " << i << " ";
				std::cout << "(" << hashtable[i].key() << " : " << hashtable[i].value() << ")" << std::endl;
			}
		}
	}
};


