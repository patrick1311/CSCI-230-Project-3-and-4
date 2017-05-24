#include <iostream>

int sfold(char*);
int ELFhash(char*);

int main() {
	std::cout << "HELLO WORLD" << std::endl;
	std::cout << "sfold : " << sfold("HELLO WORLD") << std::endl;
	std::cout << "ELFhash: " << ELFhash("HELLO WORLD") << std::endl << std::endl;
	std::cout << "NOW HEAR THIS" << std::endl;
	std::cout << "sfold : " << sfold("NOW HEAR THIS") << std::endl;
	std::cout << "ELFhash: " << ELFhash("NOW HEAR THIS") << std::endl << std::endl;
	std::cout << "HEAR THIS NOW" << std::endl;
	std::cout << "sfold : " << sfold("HEAR THIS NOW") << std::endl;
	std::cout << "ELFhash: " << ELFhash("HEAR THIS NOW") << std::endl << std::endl;
}

int sfold(char* key)
{
	unsigned int M = 101;
	unsigned int *lkey = (unsigned int *)key;
	int intlength = strlen(key) / 4;
	unsigned int sum = 0;
	for (int i = 0; i < intlength; i++)
	{
		sum += lkey[i];
	}
	int extra = strlen(key) - intlength * 4;
	char temp[4];
	lkey = (unsigned int *)temp;
	lkey[0] = 0;
	for (int j = 0; j < extra; j++)
	{
		temp[j] = key[intlength * 4 + j];
	}
	sum += lkey[0];
	return sum % M;
}

int ELFhash(char* key)
{
	unsigned int M = 101;
	unsigned long h = 0;
	while (*key)
	{
		h = (h << 4) + *key++;
		unsigned long g = h & 0xF0000000L;
		if (g) h ^= g >> 24;
		h &= ~g;
	}
	return h % M;
}