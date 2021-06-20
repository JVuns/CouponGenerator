#include <iostream>
#include <string>
#include <list>
#define SIZE 10
#define CodeNum 12
#define Multiplier 12

using namespace std;

class HashTable{
		list<pair<int, string>> table[SIZE];
		bool isEmpty();
		int Hash(char* s, int size);
		void Search();
		void Insert(string s, int n);
};

int HashTable::Hash(char *s, int listsize){
	int i;
	unsigned long hashcode;
	hashcode= 0;
	for (i=0; s[i]!='\0'; i++)
	hashcode = hashcode*Multiplier + s[i];
	return (hashcode % listsize);
	} 

bool Insert(string n, int n){
	
}

void HashTable::Search() {
	cout<<"LMAO";
}
int main(){
	HashTable table;
	cout<<"LOl";
	table.Search();
}
