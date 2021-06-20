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

struct Node
{
    string key;      
    string value; 
    Node *next;
    Node(char* Key, string Value) : key(Key), value(Value), next(0){}; //quality of life constructor(?)
};

int Hash(char *s, int listsize){ //Random hashing
	int i;
	unsigned long hashcode;
	hashcode= 0;
	for (i=0; s[i]!='\0'; i++)
	hashcode = hashcode*Multiplier + s[i];
	return (hashcode % listsize);
	} 

class HashTable{
	public:
		insertData(char* k, string val);
		hash();
		findNode(char* address);
		struct Node* arr[SIZE] = {0};
		bool isEmpty;
};

HashTable::insertData(char* k, string val){
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

HashTable::findNode(char* address){
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

char* generateCode(){
	const char chArray[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"; //alphanumeric
	static char s[16];
	timeval t1;
	gettimeofday(&t1, NULL);
	srand(t1.tv_usec * t1.tv_sec); //To make sure that rand() use a fraction of a second large to get different time seed
	for (int i = 0; i<CodeNum; i++){
		s[i] = chArray[rand() % (35)]; //Simple modulus to make sure the func return max number of 35
	}
	return s;
}

int main(){
	char* hashTable[5];
	char* code = generateCode();
	cout<<code<<endl;
	int address;
	address = Hash(generateCode(), SIZE);
	cout<<address<<endl;
	hashTable[address] = code;
	cout<<hashTable[Hash(generateCode(), SIZE)]<<" address is "<<Hash(generateCode(), SIZE)<<endl;
	HashTable nameVAr;
	
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



