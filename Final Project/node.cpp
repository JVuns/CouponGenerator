#include <iostream>
#include <chrono>
#include <time.h>
#include <list>
#include <string>	 
#include <sys/time.h>
#define CodeNum 12
#define Multiplier 12
#include "node.h"

using namespace std;

Node::Node(char* Key, string Value)
{
	key = Key;
	value = Value;
	next = 0;
}
