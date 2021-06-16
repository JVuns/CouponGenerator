#include <iostream>
#include <chrono>
#include <time.h>
#include <string>
#define CodeNum 12
#define Multiplier 12
#define SIZE 3
using namespace std;

char* generateCode(){
	const char chArray[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	static char s[16];
	srand(time(NULL)); //To make sure that rand() use a large different time seed
	for (int i = 0; i<CodeNum; i++){
		s[i] = chArray[rand() % (35)]; //Simple modulus to make sure the func return max number of 35
	}
	return s;
}

int Hash(char *s, int listsize){
	int i;
	unsigned long hashcode;
	hashcode= 0;
	for (i=0; s[i]!='\0'; i++)
	hashcode = hashcode*Multiplier + s[i];
	return (hashcode % listsize);
	} 

int main(){
	char* hashTable[5];
//	while()
	char* code = generateCode();
	cout<<code<<endl;
//	cout<<generateCode()<<endl;
	int address;
	address = Hash(generateCode(), SIZE);
	cout<<address<<endl;
//	cout<<Hash(generateCode(), SIZE));
	hashTable[address] = code;
	cout<<hashTable[Hash(generateCode(), SIZE)]<<endl;
}



