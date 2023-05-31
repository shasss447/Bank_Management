# Bank_Management

This is a basic bank managment app developed compeletely in c++. The main functions are to open a new 
account and deposit some money(no withdrawal as its a new account :)), provide a unique account number
to every account using the name and phone number, logging in a existing account using account number and 
password and trasfer of money to your bank account, or with other existing accounts.


## How does it gives a unique account number to every account?

To ensure each account has a unique account number, a struct is declared to hold the general credentials of the account holder, such as name, age and phone number. A unique account number is generated using a simple hash function that takes the name and phone number as input. An unordered map is then created with the account number as the key and the struct object as the value. After storing the account details in the unordered map, the information is also printed on a text file.


## How do withdrawal and deposit functions work?

When the account number and password are entered, the stored details are displayed on the screen along with an option to alter the account balance. If the user chooses to change the balance, it is instantly updated in the hash map. However, updating the balance in the text file requires a few additional steps. First, the app searches for the account number and creates a temporary string variable to store all the details, including the updated balance. Then, it replaces the line in the text file corresponding to that account number, updating the old balance with the new one. The advantage of this approach is that it avoids the need to create a new file or overwrite all the other account credentials to make changes to a single account. Instead, it targets the specific account and makes the necessary updates without affecting others.
