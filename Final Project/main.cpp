#include <iostream>
#include <chrono>
#include <time.h>
#include <list>
#include <string>	 
#include <sys/time.h>
#include <thread>
#define CodeNum 12
#define Multiplier 12
#define SIZE 3
#include "hash.h"
#include "node.h"
#include "genCode.h"
#include "hashTableBucket.h"
#include "hashTableLL.h"
#include "hashLin.h"
#include "hashlin.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	HashTableBucket nameVAr;
	HashTableLL nameLL;
	HashTableLin nameLin;
	bool running;
	running = true;
	while(running){
		int a;
		cout<<"Choose an option"<<endl;
		cout<<"1. Bucket hashing"<<endl;
		cout<<"2. Linear probe"<<endl;
		cout<<"3. Linked list"<<endl;
		cout<<"4. Search (Bucket)"<<endl;
		cout<<"5. Search (probe)"<<endl;
		cout<<"6. Search (LL)"<<endl;
		cout<<"7. Time Plot"<<endl;
		cin>>a;
		switch(a){
			case 1:{
				string val;
				int num;
				cout<<"Insert value: ";
				cin>>val;
				bool wrong = true;
				while (wrong){
					cout<<endl<<"Insert number of coupons: ";
					cin>>num;
					if(num>SIZE){
						cout<<"It is over the hash size, try another number";
					}
					else{
						break;
					}
				}
				char *array[num];
				for(int i = 0; i<num; i++){
					auto a = generateCode();
					cout<<endl<<a<<endl;
					nameVAr.insertData(a, val);
					nameVAr.findNode(a);
					
				}
				break;
			}
			case 2:{
				string val;
				int num;
				cout<<"Insert value: ";
				cin>>val;
				cout<<endl<<"Insert number of coupons: ";
				cin>>num;
				bool wrong = true;
				while (wrong){
					cout<<endl<<"Insert number of coupons: ";
					cin>>num;
					if(num>SIZE){
						cout<<"It is over the hash size, try another number";
					}
					else{
						break;
					}
				}
				char *array[num];
				for(int i = 0; i<num; i++){
					auto a = generateCode();
					cout<<endl<<a<<endl;
					nameLL.insertData(a, val);
					nameLL.findNode(a);
					}
				break;
			}
			case 3:{
				string val;
				int num;
				cout<<"Insert value: ";
				cin>>val;
				bool wrong = true;
				while (wrong){
					cout<<endl<<"Insert number of coupons: ";
					cin>>num;
					if(num>SIZE){
						cout<<"It is over the hash size, try another number";
					}
					else{
						break;
					}
				}
				char *array[num];
				for(int i = 0; i<num; i++){
					auto a = generateCode();
					cout<<endl<<a<<endl;
					nameLL.insertData(a, val);
					nameLL.findNode(a);
				}
				break;
			}
			case 4:{
				string input;
				cout<<"Enter coupon code ";
				cin>>input;
				char* char_arr;
			    string str_obj(input);
    			char_arr = &str_obj[0];
    			nameVAr.findNode(char_arr);
    			cout<<endl;
    			break;
			}
			case 5:{
				string input;
				cout<<"Enter coupon code ";
				cin>>input;
				char* char_arr;
			    string str_obj(input);
    			char_arr = &str_obj[0];
    			nameLin.findNode(char_arr);
    			cout<<endl;
    			break;
			}
			case 6:{
				string input;
				cout<<"Enter coupon code ";
				cin>>input;
				char* char_arr;
			    string str_obj(input);
    			char_arr = &str_obj[0];
    			nameLL.findNode(char_arr);
    			cout<<endl;
    			break;
			}
			case 7:{
				string val;
				int num;
				cout<<"Insert value: ";
				cin>>val;
				bool wrong = true;
				while (wrong){
					cout<<endl<<"Insert number of coupons: ";
					cin>>num;
					if(num>SIZE){
						cout<<"It is over the hash size, try another number";
					}
					else{
						break;
					}
				}
				char *array[num];
				auto a = generateCode();
				for(int i = 0; i<num; i++){
					a = generateCode();
					cout<<endl<<a<<endl;
					nameVAr.insertData(a, val);
					nameLL.insertData(a, val);
					nameLin.insertData(a, val);
				}
				char* char_arr;
    			auto start = chrono::steady_clock::now();
    			cout<<endl;
    			nameVAr.findNode(a);
    			auto end = chrono::steady_clock::now();
    			double time = double(chrono::duration_cast<chrono::nanoseconds>(end-start).count());
    			cout<<endl;
    			cout<<"runtime for bucket res search: "<<time<<"ns"<<endl;
    			auto start1 = chrono::steady_clock::now();
    			cout<<endl;
    			nameLL.findNode(a);
    			auto end1 = chrono::steady_clock::now();
    			double time1 = double(chrono::duration_cast<chrono::nanoseconds>(end1-start1).count());
    			cout<<"runtime for linked list res search: "<<time1<<"ns"<<endl;
    			cout<<endl;
    			auto start2 = chrono::steady_clock::now();
    			nameLin.findNode(a);
    			auto end2 = chrono::steady_clock::now();
    			double time2 = double(chrono::duration_cast<chrono::nanoseconds>(end2-start2).count());
    			cout<<endl;
    			cout<<"runtime for linked lin res search: "<<time2<<"ns"<<endl;
    			cout<<endl;
				break;
			}
		}
		
		
		//Static test
//		char t[] = "ABWD1234AAWSDA";
//		char t1[] = "ADWAWW5AF";
//		char t2[] = "JKLMNOPQRSTUVWXYZ1234567890";
//		char t3[] = "ABCDEFGHIJKLMNOPQRSTUVWX";
//		char t4[] = "ABCDEFYZ1234567890";
//		nameVAr.insertData(t, "Free salmon");
//		nameVAr.insertData(t1, "Free melon");
//		nameVAr.insertData(t2, "Free apple");
//		nameVAr.insertData(t3, "Free tick");
//		nameVAr.insertData(t4, "Free duck");
//		nameVAr.findNode(t4);
	}
}
