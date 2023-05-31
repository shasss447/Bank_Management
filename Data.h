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







void data_register(unordered_map<string, account_credentials>& directory,string acc_no, const string &account_file)
{
	int a;
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
		if (a==1)
		{
			cout << "How much amount you want to deposit" << endl;
			cin >> directory[acc_no].balance;
			outputFile << directory[acc_no].balance << endl;
			cout << directory[acc_no].balance << " " << "deposited to your account" << endl;	
		}
		else
			outputFile << directory[acc_no].balance << endl;
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
	inputFile.open(account_file, ios::in|ios::out);
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
					cout << "Press 1 for deposit    2 for withdrawal    3 for transfer to another account    4 for exit" << endl;
					cin >> a;
					if (a == 1)
					{
						double amount;
						cout << "Enter amount to deposit" << endl;
						cin >> amount;
						add_balance(directory, acc,amount);
						cout << "Your updated balance is-" << " " << directory[acc].balance << endl;
					}
					else if (a == 2)
					{
						double amount;
						cout << "Enter amount to withdraw" << endl;
						cin >> amount;
						while (amount > directory[acc].balance)
						{
							cout << "Entered amount is greater than account balance" << endl;
							cout << "Enter amount to withdraw" << endl;
							cin >> amount;
						}
						subtract_balance(directory, acc,amount);
						cout << "Your updated balance is-" << " " << directory[acc].balance << endl;
					}
					else if (a == 3)
					{
						cout << "Enter account number of the account to which money is to be transferred" << endl;
						string acc2;
						cin >> acc2;
						if (directory.find(acc2) != directory.end())
						{
							double amount;
							cout << "Enter amount to be transferred" << endl;
							cin >> amount;
							while (amount > directory[acc].balance)
							{
								cout << "Entered amount is greater than account balance" << endl;
								cout << "Enter amount to withdraw" << endl;
								cin >> amount;
							}
							another_balance(directory, acc,acc2,amount);
							cout << "Your updated balance is-" << " " << directory[acc].balance << endl;
						}
					}
					inputFile.close();
					return;
				}

			}
		}
		cout << "Account not found1!!" << endl;
		inputFile.close();
		return;
	}
}