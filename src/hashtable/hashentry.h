#ifndef HASHENTRY
#define HASHENTRY

#include <string>

class HashEntry{
public:
	HashEntry(int pData, std::string pKey){
		_data = pData;
		_key = pKey;
	}

	int getData() const {
		return _data;
	}

	std::string getKey() const {
		return _key;
	}

	bool operator==(std::string& pEntry){
		return _key == pEntry;
	}
	bool operator!=(std::string& pEntry){
		return _key != pEntry;
	}
	bool operator<=(std::string& pEntry){
		return _key <= pEntry;
	}
	bool operator<(std::string& pEntry){
		return _key < pEntry;
	}
	bool operator>=(std::string& pEntry){
		return _key >= pEntry;
	}
	bool operator>(std::string& pEntry){
		return _key > pEntry;
	}

	bool operator==(HashEntry& pEntry){
		return _key == pEntry.getKey();
	}
	bool operator!=(HashEntry& pEntry){
		return _key != pEntry.getKey();
	}
	bool operator<=(HashEntry& pEntry){
		return _key <= pEntry.getKey();
	}
	bool operator<(HashEntry& pEntry){
		return _key < pEntry.getKey();
	}
	bool operator>=(HashEntry& pEntry){
		return _key >= pEntry.getKey();
	}
	bool operator>(HashEntry& pEntry){
		return _key > pEntry.getKey();
	}

private:
	int _data;
	std::string _key;
};


#endif /* HASHENTRY */
