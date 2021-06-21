#include <iostream>
#include <chrono>
#include <time.h>
#include <list>
#include <string>	 
#include <sys/time.h>
#define CodeNum 12
#define Multiplier 12
#define BUCKET_LIM 2
#include "node.h"
#include "hash.h"
#include "genCode.h"
#include "hashTableBucket.h"

using namespace std;

HashTableBucket::insertData(char* k, string val){
	int keyv = Hash(k, SIZE);
	isEmpty = false;
	if(arr[keyv] == 0)
	isEmpty = true;
	if(isEmpty){
		auto aNode = new Node(k, val); //create new node
		aNode->key = k;
		aNode->value = val;
		aNode->next = NULL;
		arr[keyv] = aNode; //store node into key
	}
	if(!isEmpty){
		cout<<"found something, going to add to the bucket"<<endl;
		auto temp = arr[keyv];
		int lim = 0;
		while(!isEmpty){
			lim++;
			
			// happens when bucket is full
			if (lim > BUCKET_LIM)
			{
				cout << "Bucket is full. finding another empty bucket";
				int thisKey = keyv;
				keyv++;
				if (keyv > BUCKET_LIM)
				{
					keyv = 0;
				}
				while (keyv != thisKey)
				{
					if(temp->next == NULL)
					{
						auto aNode = new Node(k, val);
						aNode->next = NULL;
						temp->next = aNode;
						keyv = thisKey;
						isEmpty = true;
					}
					else
					{
						temp = temp->next;	
					}
				}
			} 
			// happens when bucket is still not full
			else 
			{
				if(temp->next == NULL)
			    {
					auto aNode = new Node(k, val);
					aNode->next = NULL;
					temp->next = aNode;
					isEmpty = true;
				}
				else
				{
					temp = temp->next;	
				}
			}
		}
	}
}

HashTableBucket::findNode(char* address){
	auto rAddress = Hash(address, SIZE);
	bool found = false;
	int lim = 0;
	while (!found && lim < SIZE)
	{
		auto temp = arr[rAddress];
		while (temp != NULL)
		{
			if (temp->key == address)
			{
				found = true;
				cout << temp->value;
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
		lim++;
	}
	if (!found)
	{
		cout << "not found in the hashTable.";
	}
}
