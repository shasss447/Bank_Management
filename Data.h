#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<unordered_map>
#include<cmath>
#include <sstream>
#include<vector>
using namespace std;
const string account_file="account_file.txt";
struct account_credentials  // structure of a account
{
	string name;
	int age;
	long long phone_num;
	string password;
};

void data_register(unordered_map<string, account_credentials>& directory,const string &account_file)
{
	fstream outputFile;
	outputFile.open(account_file,ios::app);
	if (outputFile.is_open())
	{
		for (const auto& itr : directory) {
			const string& acc_no = itr.first;
			const account_credentials& credentials = itr.second;

			outputFile << acc_no << "," << credentials.name << "," << credentials.age
				<< "," << credentials.password << "," << credentials.phone_num << endl;
		}
		cout << "Account Created Successfully!!" << endl;
		outputFile.close();
	}
	else
		cout << "Failed to open the file for saving account data."<<endl;
	return;
}
void data_retrieval(unordered_map<string, account_credentials>& directory, string acc, string pass)
{
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
			if (tokens.size() >= 4)
			{
				string acc_nof = tokens[0];
				string passf = tokens[3];
				if (acc_nof == acc && passf == pass)
				{
					cout << "Account Found!!" << endl;
					cout << tokens[1] << " " << tokens[2] << " " << tokens[4] << endl;
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
