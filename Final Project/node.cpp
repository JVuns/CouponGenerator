#include <iostream>
#include <string>
#include "node.h"

using namespace std;

Node::Node(char* Key, string Value)
{
	key = Key;
	value = Value;
	next = 0;
}
