#include <iostream>
#include <chrono>
#include <time.h>
#include <list>
#include <string>	 
#include <sys/time.h>
#define CodeNum 12
#define Multiplier 12
#include "hash.h"

using namespace std;

int Hash(char *s, int listsize)
{
	int i;
	unsigned long hashcode;
	hashcode= 0;
	for (i=0; s[i]!='\0'; i++)
	hashcode = hashcode*Multiplier + s[i];
	return (hashcode % listsize);
}
