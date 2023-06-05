#pragma once
#include"Data.h"



using namespace std;
bool valid_age(int n);
bool valid_pn(long long n);
string hash_function(string name, long long pn);




// account registration function
       
void acc_register(unordered_map<string,account_credentials>&directory)  
{
	system("cls");
	string name;
	int age;
	long long phone_num;
	string password;
	double balance = 0.00;
	cout << "Enter your name"<<endl;
	cin >> name;
	cout << "Enter your age"<<endl;

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

	cout << "Create a password" << endl;
	cin >> password;

	account_credentials account;  // creating object of "account_credentials" struct
	account.name = name;
	account.age = age;
	account.phone_num = phone_num;
	account.password = password;
	string account_number = hash_function(name, phone_num);  // hash function to create a unique account number
	directory[account_number] = account;                     // pushing credentials into the unordered map
	data_register(directory,account_number,account_file);    // calling function to add the registered account in the txt file
	cout << "Press Enter to continue...";
	cin.ignore();
	cin.get();
	return;
}

// account registration function ends


// login function starts

void acc_exists(unordered_map<string, account_credentials>& directory)
{
	system("cls");
	string accno;
	string pass;
	cout << "Enter account number" << endl;
	cin >> accno;
	cout << "Enter password" << endl;
	cin >> pass;
	data_retrieval(directory, accno, pass);  // calling function to check whether the account exists or not
	cout << "Press Enter to continue...";
	cin.ignore();
	cin.get();
	return;
}

// login function ends


// helper functions

bool valid_age(int n)  // to verify if age is above 18 or not
{
    if (n >= 18)
     return 1;
    return 0;
}


bool valid_pn(long long n)  //to verify if phone number is valid or not
{
    string s = to_string(n);
    if (s.length() == 10)
      return 1;
    return 0;
}


string hash_function(string name, long long pn)  // hash function to create a unique account number to every account
{
    string p = to_string(pn);
    return name.substr(0, 2) + "00XX" + p.substr(7, 3);
}


