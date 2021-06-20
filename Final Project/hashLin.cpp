#include <iostream>
#include <chrono>
#include <time.h>
#include <list>
#include <string>	 
#include <sys/time.h>
#define CodeNum 12
#define Multiplier 12
#define SIZE 3
#define BUCKET_LIM 2
#include "node.h"
#include "hash.h"
#include "genCode.h"
#include "hashLin.h"

using namespace std;

HashTableLin::insertData(char* k, string val){
	int keyv = Hash(k, SIZE);
	isEmpty = false;
	if(arr[keyv] == 0)
	isEmpty = true;
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
		if (keyv > 2)
		{
			keyv = 0;
		}
		while(keyv != curIndex){
			if (arr[keyv] == 0)
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
				keyv++;
				if (keyv > 2)
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
	if (rAddress > 2)
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
			if (rAddress > 2)
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
