#include <iostream>
#include <list>
#include <string>	 
#define BUCKET_LIM 2
#include "node.h"
#include "hash.h"
#include "hashTableBucket.h"

using namespace std;

HashTableBucket::insertData(char* k, string val){
	int keyv = Hash(k, SIZE);
	Node* aNode = new Node(k, val); //create new node
	aNode->key = k;
	aNode->value = val;
	aNode->next = NULL;
	// if it is empty
	if (arr[keyv] == 0)
	{
		auto a = new Bucket();
		arr[keyv] = a;
		arr[keyv]->insert(aNode);
	}
}

HashTableBucket::findNode(char* address){
	int rAddress = Hash(address, SIZE);
	arr[rAddress]->searchNode(address);
}
