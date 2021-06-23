#include <iostream>
#include <string>	 

using namespace std;

#ifndef node_h
#define node_h

struct Node
{
    string key;      
    string value; 
    Node *next;
    Node(char* Key, string Value);
};

#endif
