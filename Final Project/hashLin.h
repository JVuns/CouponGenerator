#include <iostream>
#define SIZE 100

using namespace std;

#ifndef hash_Lin
#define hash_Lin

class HashTableLin{
	public:
		insertData(char* k, string val);
		findNode(char* address);
		struct Node* arr[SIZE] = {0};
		bool isEmpty;
};

#endif
