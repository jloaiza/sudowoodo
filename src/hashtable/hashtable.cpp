#include "hashtable.h"
#include "../binaryoperations/byteshandler.h"

#include <iostream>
#include <cstdlib>

HashTable::HashTable(int pLength){
	_length = pLength;
	_table = new AVLTree<HashEntry, std::string>*[pLength];
	_ocurrences = new AVLTree<int, int>();
	startTable();
}

HashTable::HashTable(){
	_length = DEFAULT_LENGTH;
	_table = new AVLTree<HashEntry, std::string>*[_length];
	_ocurrences = new AVLTree<int, int>();
	startTable();
}

void HashTable::startTable(){
	for (int i = 0; i < _length; i++){
		_table[i] = new AVLTree<HashEntry, std::string>();
	}
}

int HashTable::insert(int pValue, std::string pKey){

	int* key = new int(hash(pKey));
	std::cout<<"hash: "<<*key<<" other: "<<(_ocurrences->search(key)==0?"false":"true")<<std::endl;
	_ocurrences->insert(key);

	int index = hash(pKey)%_length;
	HashEntry* entry = new HashEntry(pValue, pKey);
	_table[index]->insert(entry);
	return index;
}

int HashTable::read(std::string pKey){
	int index = hash(pKey)%_length;
	return _table[index]->search(&pKey)->getData();
}

std::string HashTable::bin2long2bin(std::string pBinary){
	std::string buffer = "";
	for (int i = 0; i < pBinary.length() - 8; i++){
		long lnumber = BytesHandler::to_ulong(pBinary.substr(i, i+8));
		buffer += BytesHandler::unum2bin(lnumber, 8);
	}
	return buffer;
}

int HashTable::charCount(std::string pString, char pChar){
	int count = 0;
	for (int i = 0; i < pString.length(); i++){
		if (pString[i] == pChar){
			count++;
		}
	}
	return count;
}

void HashTable::erase(std::string pKey){
	int index = hash(pKey)%_length;
	_table[index]->erase(&pKey);
}

std::string HashTable::strXor(std::string pBin1, std::string pBin2){
	for (int i = 0; i < pBin1.length(); i++){
		if (pBin1[i] == pBin2[i]){
			pBin1[i] = '0';
		} else {
			pBin1[i] = '1';
		}
	}
	return pBin1;
}

int HashTable::hash(std::string pKey){

	std::string binary = BytesHandler::string2bin(pKey, pKey.length());
	std::string binLong = bin2long2bin(binary);

	int oneCount = charCount(binary, '1');
	int zeroCount = charCount(binary, '0');

	std::string oneBin = BytesHandler::unum2bin(oneCount, 4);
	std::string zeroBin = BytesHandler::unum2bin(zeroCount, 4);

	std::string out = strXor(binLong.substr(binLong.length()-17, 16), binLong.substr(16, 16));
	out += zeroBin.substr(zeroBin.length()-9, 8);
	out += oneBin.substr(oneBin.length()-9, 8);

	return (int)BytesHandler::to_ulong(out);
}