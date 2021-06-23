#include <iostream>
#include <list>
#include <string>	 
#define SIZE 100

using namespace std;

#ifndef hash_LL
#define hash_LL

class HashTableLL{
	public:
		insertData(char* k, string val);
		findNode(char* address);
		struct Node* arr[SIZE] = {0};
		bool isEmpty;
};

#endif
