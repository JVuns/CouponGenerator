#include <iostream>
#include <list>
#include <string>	 
#define SIZE 100
#include "node.h"
#include "hash.h"
#include "hashLin.h"

using namespace std;

HashTableLin::insertData(char* k, string val){
	bool nondup = true;
	int keyv = Hash(k, SIZE);
	isEmpty = false;
	if(arr[keyv] == 0)
	isEmpty = true;
	// don't need to check if it is a dupe while this is empty from the start
	if(isEmpty){
		auto aNode = new Node(k, val); //create new node
		aNode->key = k;
		aNode->value = val;
		arr[keyv] = aNode; //store node into key
	}
	if(!isEmpty){
		cout<<"already occupied will try finding another empty index"<<endl;
		int curIndex = keyv;
		keyv++;
		if (keyv > SIZE-1)
		{
			keyv = 0;
		}
		while(keyv != curIndex){
			if (arr[keyv] == 0 && nondup)
			{
				auto aNode = new Node(k, val); //create new node
				aNode->key = k;
				aNode->value = val;
				arr[keyv] = aNode;
				isEmpty = true;
				break;				
			}
			else
			{
				// checks if it the current occupied element is a nondup of the key
				if (arr[keyv]->key == k)
				{
					nondup = false;
				}
				
				keyv++;
				if (keyv > SIZE-1)
				{
					keyv = 0;
				}
			}
		}
	}
}

HashTableLin::findNode(char* address){
	int rAddress = Hash(address, SIZE);
	int curIndex = rAddress;
	bool found = false;
	if (arr[rAddress]->key == address)
	{
		found = true;
		cout << arr[rAddress]->value; 
	}
	rAddress++;
	if (rAddress > SIZE-1)
	{
		rAddress = 0;
	}
	while (!found && rAddress != curIndex)
	{
		if (arr[rAddress]->key == address)
		{
			cout << arr[rAddress]->value;
			found = true;
		}
		else
		{
			rAddress++;
			if (rAddress > SIZE-1)
			{
				rAddress = 0;
			}
		}
	}
	if (!found)
	{
		cout << "can't find node";
	}
}
