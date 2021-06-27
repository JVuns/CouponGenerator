#include <iostream>
#include <list>
#include <string>	 
#define Multiplier 12
#include "hash.h"

using namespace std;

int Hash(char *s, int listsize)
{
	int i;
	unsigned long hashcode; // to store a large number
	hashcode= 0;
	for (i=0; s[i]!='\0'; i++)
	hashcode = hashcode*Multiplier + s[i]; // multiplication method hash function
	return (hashcode % listsize); // Modulus to set the character index no greater than the actual amount of data
}
