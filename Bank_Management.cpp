#include<iostream>
#include<string>
#include"Welcome.h"
using namespace std;


int main()
{
	unordered_map<string, account_credentials>directory;
	welcome(directory);
	return 0;	
}