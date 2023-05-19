#pragma once
#include<iostream>
using namespace std;
void welcome()
{
	cout << "Welcome to Omen Bank\n";
	cout << "Click to continue :\n";
	cout << "1) To open new account        2) To open existing account\n";
	bool a = true;
	while(a)
	{
		int n;
		cin >> n;
		switch (n)
		{
		case 1:acc_register();
			a = !a;
			break;
		case 2:acc_exists();
			a = !a;
			break;
		default:
			cout << "Enter specified numbers\n";
		}
	}
	
	
}
