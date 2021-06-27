#include <iostream>
#include <list>
#include <string>
#include "node.h" 
#define SIZE 100

using namespace std;

#ifndef hash_bucket
#define hash_bucket

struct Bucket
{
	struct Node* arr[3] = {NULL, NULL, NULL};
	int curIndex = 0;
	bool nondup;
	
	void insert(Node* aNode)
	{	
		nondup = true;
		int iter;
		// checks whether the key is not a duplicate. Will not be inserted if it is a duplicate.
		for (iter = 0; iter < curIndex; iter++)
		{
			if (arr[iter]->key == aNode->key)
			{
				nondup = false;
			}
		}
		
		// if it is not full
		if (curIndex < 3 && nondup == true)
		{	
			arr[curIndex] = aNode;
			curIndex++;
		}
	}
	
	void searchNode(char* address)
	{	
		if (arr[0] != NULL)
		{
			if (arr[0]->key == address)
			cout << arr[0]->value;
		}
		
		if (arr[1] != NULL)
		{
			if (arr[1]->key == address)
			cout << arr[1]->value;
		}
		
		if (arr[2] != NULL)
		{
			if (arr[2]->key == address)
			cout << arr[2]->value;
		}
	}
};

class HashTableBucket{
	public:
		insertData(char* k, string val);
		findNode(char* address);
		struct Bucket* arr[SIZE] = {0};
		bool isEmpty;
};

#endif
