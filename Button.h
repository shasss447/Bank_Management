#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
bool valid_age(int n)
{
	if (n >= 18)
		return 1;
	return 0;
}
void acc_register()
{
	string name;
	int age;
	bool c_age=false;
	cout << "Enter your name\n";
	cin >> name;
	cout << "Enter your age\n";
	while(1)
	{	
		cin >> age;
		if (valid_age(age))
			break;
		cout << "Age should be greater than or equal to 18\n";
	}

	cout << name << " " << age;
	
}
void acc_exists()
{
	string accno;
	string pass;
	cout << "Enter account number\n";
	cin >> accno;
	cout << "Enter password\n";
	cin >> pass;
	cout << accno << " " << pass;
}
