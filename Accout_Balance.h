#pragma once
#include<iostream>
#include<fstream>
using namespace std;

const string account_file = "account_file.txt";

struct account_credentials  // structure of a account
{
	string name;
	int age;
	long long phone_num;
	string password;
	double balance = 0.00;
};

void new_balance(unordered_map<string, account_credentials>& directory, double upbal, string acc);

void add_balance(unordered_map<string, account_credentials>& directory, string acc)
{
	int amount;
	cout << "Enter amount to deposit" << endl;
	cin >> amount;
	directory[acc].balance = directory[acc].balance + amount;
	new_balance(directory, directory[acc].balance, acc);
	cout << "Your updated balance is-" << " " << directory[acc].balance << endl;
	std::cout << "Press Enter to continue...";
	std::cin.ignore(); // Clear input buffer
	std::cin.get();
}

void subtract_balance(unordered_map<string, account_credentials>& directory, string acc)
{
	int amount;
	cout << "Enter amount to withdraw" << endl;
	cin >> amount;
	if (amount <= directory[acc].balance)
	{
		directory[acc].balance = directory[acc].balance - amount;
		new_balance(directory, directory[acc].balance, acc);
		cout << "Your updated balance is-" << " " << directory[acc].balance << endl;
		std::cout << "Press Enter to continue...";
		std::cin.ignore(); // Clear input buffer
		std::cin.get();
	}
	else
	{
		cout << "Entered amount is greater than account balance" << endl;
		subtract_balance(directory, acc);
	}
		
}



void new_balance(unordered_map<string, account_credentials>& directory, double upbal, string acc)
{
	fstream file;
	file.open(account_file, ios::in | ios::out);

	if (file.is_open()) {
		vector<string> lines;
		string line;
		while (getline(file, line)) {
			lines.push_back(line);
		}

		// Find and update the desired entry
		for (auto& entry : lines) {
			stringstream ss(entry);
			string acc_no_str;
			getline(ss, acc_no_str, ',');
			if (acc_no_str == acc) {
				// Update the balance
				stringstream temp_ss;
				temp_ss << acc << "," << directory[acc].name << "," << directory[acc].age
					<< "," << directory[acc].password << "," << directory[acc].phone_num
					<< "," << to_string(upbal);
				entry = temp_ss.str();
				break;
			}
		}

		file.close();

		file.open(account_file, ios::out);
		if (file.is_open()) {
			for (const auto& entry : lines) {
				file << entry << endl;
			}
			file.close();
		}
	}
}