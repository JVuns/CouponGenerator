#include <iostream>
#include <chrono>
#include <time.h>
#include <list>
#include <string>	 
#include <sys/time.h>
#define CodeNum 12
#define Multiplier 12
#include "genCode.h"

using namespace std;

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
