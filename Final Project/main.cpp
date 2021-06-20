#include <iostream>
#include <chrono>
#include <time.h>
#include <list>
#include <string>	 
#include <sys/time.h>
#define CodeNum 12
#define Multiplier 12
#define SIZE 3
#include "hash.h"
#include "node.h"
#include "genCode.h"
#include "hashTableBucket.h"
#include "hashTableLL.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	// test for the hash table using bucket collision resolve
	char* hashTable[5];
	char* code = generateCode();
	cout<<code<<endl;
	int address;
	address = Hash(code, SIZE);
	cout<<address<<endl;
	hashTable[address] = code;
	cout<<hashTable[Hash(code, SIZE)]<<" address is "<<Hash(code, SIZE)<<endl;
	HashTableBucket nameVAr;
	
	//Static test
	char t[] = "ABWD1234AAWSDA";
	char t1[] = "ADWAWW5AF";
	char t2[] = "JKLMNOPQRSTUVWXYZ1234567890";
	char t3[] = "ABCDEFGHIJKLMNOPQRSTUVWX";
	char t4[] = "ABCDEFYZ1234567890";
	nameVAr.insertData(t, "Free salmon");
	nameVAr.insertData(t1, "Free melon");
	nameVAr.insertData(t2, "Free apple");
	nameVAr.insertData(t3, "Free tick");
	nameVAr.insertData(t4, "Free duck");
	nameVAr.findNode(t4);
}
