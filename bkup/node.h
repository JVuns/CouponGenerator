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
