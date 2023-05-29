#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<unordered_map>
#include<cmath>
#include <sstream>
#include<vector>
#include"Accout_Balance.h"
using namespace std;
const string account_file="account_file.txt";
struct account_credentials  // structure of a account
{
	string name;
	int age;
	long long phone_num;
	string password;
	double balance=0.00;
};

void data_register(unordered_map<string, account_credentials>& directory,string acc_no, const string &account_file)
{
	bool a;
	fstream outputFile;
	outputFile.open(account_file,ios::app);
	if (outputFile.is_open())
	{
			outputFile << acc_no << "," << directory[acc_no].name << "," << directory[acc_no].age
				<< "," << directory[acc_no].password << "," << directory[acc_no].phone_num<<",";
		cout << "Account Created Successfully!!" << endl;
		cout << "Do you want to deposite some money in your new accout" << endl;
		cout << "Press 1 for yes and 2 for no" << endl;
		cin >> a;
		if (a)
		{
			cout << "How much amount you want to transfer" << endl;
			cin >> directory[acc_no].balance;
			outputFile << directory[acc_no].balance << endl;
			cout << directory[acc_no].balance << " " << "deposited to your account" << endl;	
		}
		outputFile.close();
	}
	else
		cout << "Failed to open the file for saving account data."<<endl;
	return;
}
void data_retrieval(unordered_map<string, account_credentials>& directory, string acc, string pass)
{
	int a;
	fstream inputFile;
	inputFile.open(account_file, ios::in);
	if (inputFile.is_open())
	{
		string line;
		while (getline(inputFile, line))
		{
			stringstream ss(line);
			string token;
			vector<string>tokens;
			while (getline(ss, token, ','))
			{
				tokens.push_back(token);
			}
			if (tokens.size() >= 5)
			{
				string acc_nof = tokens[0];
				string passf = tokens[3];
				if (acc_nof == acc && passf == pass)
				{
					cout << "Account Found!!" << endl;
					cout <<"Your name-"<< tokens[1] << "\n" <<"Your age-"<< tokens[2] << "\n" <<"Your phone number-"<< tokens[4] << "\n" <<"Your balance-"<< tokens[5] << endl;
					cout << "Do you want to deposit or withdraw money from your account" << endl;
					cout << "Press 1 for deposit    2 for withdrawal    3 for exit" << endl;
					cin >> a;
					if (a == 1)
					{
						int amount;
						cout << "Enter amount to deposit" << endl;
						cin >> amount;
						directory[acc].balance = directory[acc].balance + amount;

						cout << "Your updated balance is-" << " " << directory[acc].balance << endl;
					}
					else if (a == 2)
					{
						int amount;
						cout << "Enter amount to withdraw" << endl;
						cin >> amount;
						directory[acc].balance = directory[acc].balance - amount;
						cout << "Your updated balance is-" << " " << directory[acc].balance << endl;
					}
					cout << "Thank You!!" << endl;
					return;
				}

			}
		}
		cout << "Account not found1!!" << endl;
		inputFile.close();
		return;
	}
}


void return_vec()
