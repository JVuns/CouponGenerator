#include <iostream>
#include <chrono>
#include <time.h>
#include <list>
#include <string>	 
#include <sys/time.h>
#define CodeNum 12
#define Multiplier 12
#define BUCKET_LIM 2
#define SIZE 100
#include "node.h"
#include "hash.h"
#include "genCode.h"
#include "hashTableLL.h"

using namespace std;

HashTableLL::insertData(char* k, string val){
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
		cout<<"linking another node to the linked list"<<endl;
		auto temp = arr[keyv];
		while(!isEmpty){
			if(temp->next == NULL){
				auto aNode = new Node(k, val);
				aNode->next = NULL;
				temp->next = aNode;
				isEmpty = true;
			}
			else{
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
