#include <iostream>
#include <list>
#include <string>	 
#define SIZE 100
#include "node.h"
#include "hash.h"
#include "hashTableLL.h"

using namespace std;

HashTableLL::insertData(char* k, string val){
	int keyv = Hash(k, SIZE);
	isEmpty = false;
	// no need to check the if it is unique if this is empty since that means that the index is always gonna be computed using a fixed formula
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
		cout<<"linking another node to the linked list"<<endl;
		auto temp = arr[keyv];
		while(!isEmpty){
			// no need to checked in here too.
			if(temp->next == NULL && temp->key != k){
				auto aNode = new Node(k, val);
				aNode->next = NULL;
				temp->next = aNode;
				isEmpty = true;
			}
			else{
				// checks if the this is not a dupe key
				if (temp->key == k)
				{
					break;
				}
				temp = temp->next;	
			}
		}
	}
}

HashTableLL::findNode(char* address){
	auto rAddress = Hash(address, SIZE);
	if(arr[rAddress]->next == NULL){
	cout<<arr[rAddress]->value<<endl;
	}
	else{
		auto temp = arr[rAddress];
		while(address != temp->key){
			temp = temp->next;
		}
	cout<<temp->value;
	}
}
