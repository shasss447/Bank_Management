#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<unordered_map>
#include<cmath>
using namespace std;
bool valid_age(int n);
bool valid_pn(long n);
string hash_function(string name, long pn);
struct account_credentials
{
	string name;
	int age;
	long phone_num;
	string password;
};
;
void acc_register(unordered_map<string,account_credentials>&directory)
{
	system("cls");
	string name;
	int age;
	long long phone_num;
	string password;
	cout << "Enter your name"<<endl;
	cin >> name;
	cout << "Enter your age ";
	while(1)
	{	
		cin >> age;
		if (valid_age(age))
			break;
		cout << "Age should be greater than or equal to 18"<<endl;
	}
	cout << "Enter your phone number"<<endl;
	while (1)
	{
		cin >> phone_num;
		if (valid_pn(phone_num))
			break;
		cout << "Phone number should be of 10-digits" << endl;
	}
	cout << phone_num << endl;
	cout << "Create a password" << endl;
	cin >> password;
	account_credentials account;
	account.name = name;
	account.age = age;
	account.phone_num = phone_num;
	account.password = password;
	string hashed_credential = hash_function(name, phone_num);
	directory[hashed_credential] = account;
	cout << name << " " << age << " "<<phone_num << " " << password << " " << hashed_credential;
	
}
void acc_exists()
{
	system("cls");
	string accno;
	string pass;
	cout << "Enter account number" << endl;
	cin >> accno;
	cout << "Enter password" << endl;
	cin >> pass;
	cout << accno << " " << pass;
}

bool valid_age(int n)
{
	if (n >= 18)
		return 1;
	return 0;
}
bool valid_pn(long n)
{
	string s = to_string(n);
	if (s.length() == 10)
		return 1;
	return 0;

}
string hash_function(string name, long pn)
{
	string p = to_string(pn);
	return name.substr(0, 2) + "00XX" + p.substr(7, 3);

}
