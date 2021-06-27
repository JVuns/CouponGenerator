#include <iostream>
#include <string>
#include "node.h"

using namespace std;

Node::Node(char* Key, string Value) // node structure that contain key address and it's value
{
	key = Key;
	value = Value;
	next = 0;
}
