#pragma once
#include<string>
#include<unordered_map>
#include<cmath>
#include <sstream>
#include<vector>
#include"Accout_Balance.h"

using namespace std;



void data_register(unordered_map<string, account_credentials>& directory,string acc_no, const string &account_file)
{
	int a;
	fstream outputFile;                          // creating object of fstream 
	outputFile.open(account_file,ios::app);      // opening the file in 'append' mode

	if (outputFile.is_open())
	{
		outputFile << acc_no << "," << directory[acc_no].name << "," << directory[acc_no].age        // adding data of new account in the txt file
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

		outputFile.close();                     // closing the file
	}

	else
		cout << "Failed to open the file for saving account data."<<endl;

	return;
}



void data_retrieval(unordered_map<string, account_credentials>& directory, string acc, string pass)
{
	int a;
	fstream inputFile;                                   // creating fstream object
	inputFile.open(account_file, ios::in|ios::out);      // opening file in input and output mode

	if (inputFile.is_open())
	{
		string line;

		while (getline(inputFile, line))    // storing data of a account in a single string
		{
			stringstream ss(line);          // creating object of stringstream
			string token;
			vector<string>tokens;

			while (getline(ss, token, ','))
			{
				tokens.push_back(token);   // pushing the data in the vector
			}

			if (tokens.size() >= 5)
			{
				string acc_nof = tokens[0];
				string passf = tokens[3];

				if (acc_nof == acc && passf == pass)
				{
					cout << "Account Found!!" << endl;
					cout <<"Your name-"<< tokens[1] << "\n" <<"Your age-"<< tokens[2] << "\n" <<"Your phone number-"
						 << tokens[4] << "\n" <<"Your balance-"<< tokens[5] << endl;
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

						subtract_balance(directory, acc,amount);           // calling function to update the balance accordingly
						cout << "Your updated balance is-" << " " << directory[acc].balance << endl;
					}

					else if (a == 3)
					{
						cout << "Enter account number of the account to which money is to be transferred" << endl;
						string acc2;
						cin >> acc2;

						if (directory.find(acc2) != directory.end())  // checking whether stated account exists or not
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

							another_balance(directory, acc,acc2,amount);  // updating balances of both the accounts involved in the transaction
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