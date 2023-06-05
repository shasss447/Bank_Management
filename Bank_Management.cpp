#include"Welcome.h"
using namespace std;


int main()
{
	unordered_map<string, account_credentials>directory;  // unordered map to store basic details
	welcome(directory);
	return 0;	
}