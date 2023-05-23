#pragma once
#include<iostream>
#include"Account.h"
using namespace std;



void welcome()
{
	unordered_map<string, account_credentials>directory;
	cout << "________________________" << endl;
	cout << "  Welcome to Omen Bank" << endl;
	cout << "  Click to continue :" << endl;
	cout << "1) To open new account        2) To open existing account" << endl;
	bool a = true;
	while(a)
	{
		int n;
		cin >> n;
		switch (n)
		{
		case 1:acc_register(directory);
			a = !a;
			break;
		case 2:acc_exists(directory);
			a = !a;
			break;
		default:
			cout << "Enter specified numbers" << endl;
		}
	}
	return;
}
