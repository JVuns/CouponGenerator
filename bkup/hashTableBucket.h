#include <iostream>
#include <chrono>
#include <time.h>
#include <list>
#include <string>	 
#include <sys/time.h>
#define CodeNum 12
#define Multiplier 12
#define SIZE 3

using namespace std;

#ifndef hash_bucket
#define hash_bucket

class HashTableBucket{
	public:
		insertData(char* k, string val);
		findNode(char* address);
		struct Node* arr[SIZE] = {0};
		bool isEmpty;
};

#endif
