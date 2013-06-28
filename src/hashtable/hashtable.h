#ifndef HASHTABLE
#define HASHTABLE

#include <string>
#include "hashentry.h"
#include "../structures/avltree/avltree.h"

class HashTable {
public:
	HashTable(int pLength);
	HashTable();
	int insert(int pValue, std::string pKey);
	int read(std::string pKey);
	void erase(std::string pKey);

private:
	static const int DEFAULT_LENGTH = 101;
	int hash(std::string pKey);

	void startTable();
	std::string strXor(std::string pBin1, std::string pBin2);
	int charCount(std::string pString, char pChar);
	std::string bin2long2bin(std::string pBinary);
	AVLTree<HashEntry, std::string>** _table;
	AVLTree<int, int>* _ocurrences;
	int _length;

};

#endif /* HASHTABLE */