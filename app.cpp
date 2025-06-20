/* Important notices for the A2 template:
A. The group will need to use this template to work on the Assignment 2 (A2)
B. Not allowed to change the overall structure of the template including adding additional functions or remove any existing functions
C. Need to fill in the codes including the parts indicated with numbers and its descriptions
D. Extra decorations can be included without interfering the provided structure
E. You will need to define and use the parameters accordingly (including its datatype) as described below:
   P1 = two dimensional arrary (n rows and 4 columns) to store the user details
   P2 = parameter to store the username
   P3 = parameter to store total number of users
   P4 = array to store the name of the items
   P5 = array to store the code of the items
   P6 = array to store the price of the items per kilogram
   P7 = array to store the purchase weight provided by the user
   P8 = parameter to store total number of items
   P9 = parameter to store total amount of transaction
   P10 = array to store the date
   P11 = array to store the amount (top up or spend); "-" indicate spending
   P12 = parameter to store total number of transaction history
F. Please rename the parameters properly instead of using P1, P2, P3......
   Else, marks will be deducted.
G. The programme is designed with three sections and each section can be executed separately without affected
   by other sections. Comment out other sections if it is not related while working individually.
H. At the end, COMPULSORY to combine all the sections together as a complete executable program before submission.
*/

//Only these libraries (or mentioned in the lecture slides or practical) are allowed to be defined and used 
//Libraries such as #include <array>, #include <vector>, function enum, pointer (*) or others are not allowed 
//Please refer to the A2.doc for further descriptions 
//EXCEPTION: However, libraries for decoration purposes (e.g., #include <ctime>) are allowed. 
#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <string> 
#include <ciso646>
using namespace std;

#define SIZE 100 //global definition to determine the size of all the array in A2 
string currentUser = "Karen Tan Wei Wei"; //global definition with default value to determine the current user 

//1. Define the FUNCTION PROTOTYPE for all the listed functions 
void menu();
// Member 1 functions 
void readUserDetails(string userDetails[][4], int& totalUsers);
void registerNewUser();
int login(const string userDetails[][4], int totalUsers, string& userName);
// Member 2 functions 
void readItemList(string items[], string codes[], double prices[], double weights[], int& totalItems);
void addItemList(string items[], string codes[], double prices[], double weights[], int& totalItems);
void displayItemList(string items[], string codes[], double prices[], double weights[], int totalItems);
// Member 3 functions 
void readTransaction(double& totalAmountTransaction, string dates[], double amounts[], int& totalNumberTransactions);
void transaction(double& totalAmountTransaction, string dates[], double amounts[], int& totalNumberTransactions);
void displayTransactionDetails(double& totalAmountTransaction, string dates[], double amounts[], int& totalNumberTransactions);

int main() {

	//2. Define and initialise all the necessary variables 
	// Member 1 variables 
	int choice;
	int contRL = 1;
	string userDetails[SIZE][4] = { {""} }; // previously P1 
	string userName; // previously P2 
	int totalUsers = 0; // previously P3 
	int loginResult;
	// Member 2 variables 
	int totalItems = 0;
	double prices[SIZE];
	double weights[SIZE];
	string items[SIZE];
	string codes[SIZE];
	// Member 3 variables 
	double totalAmountTransaction = 0;
	string dates[SIZE];
	double amounts[SIZE];
	int totalNumberTransactions = 0;

	//--------------------- Start of Member 1 -------------------------------- 
	//3. User Module to handle new registration and login 
	do {
		//To ask whether user want to register or login 
		cout << "1. Register New User" << endl;
		cout << "2. Login" << endl;
		cout << "3. Quit" << endl;
		cout << "Choice: ";
		cin >> choice;
		cin.ignore();
		if (choice == 1) {
			//Function call registerNewUser to register new user 
			registerNewUser();
			cout << "Do you want to continue login? (1-yes, 2-no): ";
			cin >> contRL;

			if (contRL == 2)
				return 0;
		}
		else if (choice == 2) {
			//Function call readUserDetails to read the users' details from "user.txt" 
			//Function call login by returning a value for the if...else statement to handle possible conditions: 
			//1. if username and password are correct 
			//2. if username is correct but password is not correct 
			//3. if username is not correct but password is correct 
			//4. if username and password are not correct 
			//Prompt back to the login menu again if meet with condition 2, 3 and 4 
			//NOTE: set the global variable "currentUser" to the username that successfully login  
			readUserDetails(userDetails, totalUsers);
			// for conditions 2, 3 and 4, login returns -1 (error) 
			loginResult = login(userDetails, totalUsers, userName);
			if (loginResult == -1) {
				cout << "Username or Password not correct!" << endl;
				cout << "If you have not registered, please register first!" << endl;
				cout << "Do you want to continue register/login? (1-yes, 2-no): ";
				cin >> contRL;
				if (contRL == 2)
					return 0;
			}
			// for condition 1, login returns 0 (no errors) 
			else {
				currentUser = userName;
				cout << "Login Successfully!" << endl;
				system("Pause");
				contRL = 2; // breaks the loop 
			}
		}
		else return 0;
		//"cls" stand for clear screen which refreshes the screen, placing the cursor on original place. 
		//For more information, refer to https://www.quora.com/What-is-system-CLS-for-in-c++ 
		system("cls");
	} while (contRL == 1);

	//--------------------- End of Member 1 -------------------------------- 
	//--------------------- Start of Member 2 or Member 3 -------------------------------- 
	//4. Function call readItemList with the required parameters 
	readItemList(items, codes, prices, weights, totalItems);
	//5. Function call readTransaction with the required parameters 
	readTransaction(totalAmountTransaction, dates, amounts, totalNumberTransactions);

	int cont = 1;
	char selectInput = '6';
	int select = 6;

	do {//do...while iteration is implemented to repeat the selection menu as below 
		//"cls" stand for clear screen which refreshes the screen, placing the cursor on original place 
		//For more information, refer to https://www.quora.com/What-is-system-CLS-for-in-c++ 
		system("cls");

		//6. Indicate username if user able to login 
		cout << "Username: " << currentUser << endl;

		menu();

		//User will key in and select one of the functions available 
		//However, current input is accepting random value from the user without evaluation  
		//An evaluation should be carried out to ensure user only able to select 1 or 2 or 3 or 4 or 5 
		//Additional marks will be awarded to those who are able to check on the input other than numbers  
		//such as "abc" or "1abc" 
		//NOTE: ONLY this part is require input evaluation for marking purposes 
		//Tips: isdigit and stoi can be used. If you are using stoi with dev c++, you may face c++ 11 problem  
		//and please refer to https://stackoverflow.com/questions/13613295/how-can-i-compile-c11-code-with-orwell-dev-c 
		cout << "Choice: ";
		cin >> selectInput;

		if (selectInput != '1' and selectInput != '2' and selectInput != '3' and selectInput != '4' and selectInput != '5') {
			//if not 1,2,3,4 or 5 then output "Not available" 
			selectInput = '6';
		}
		//convert input from char to int and store in select 
		select = selectInput - '0';
		//"cls" stand for clear screen which refreshes the screen, placing the cursor on original place 
		//For more information, refer to https://www.quora.com/What-is-system-CLS-for-in-c++ 
		system("cls");

		//cin.ignore() is to ignore or clear one or more characters from the input buffer 
		//For more information, refer to https://www.tutorialspoint.com/what-is-the-use-of-cin-ignore-in-cplusplus 
		cin.ignore();

		//7. if...else is implemented to select the function according to the user input 
		if (select == 1)
			displayItemList(items, codes, prices, weights, totalItems);
		else if (select == 2)
			addItemList(items, codes, prices, weights, totalItems);
		else if (select == 3)
			transaction(totalAmountTransaction, dates, amounts, totalNumberTransactions);
		else if (select == 4)
			displayTransactionDetails(totalAmountTransaction, dates, amounts, totalNumberTransactions);
		else if (select == 5)
			cont = 2;
		else {
			cout << "Not available" << endl;
			system("Pause");
		}
		continue;
	} while (cont == 1);
	//--------------------- End of Member 2 or Member 3 -------------------------------- 
	return 0;
}

//Function menu --> To display the selection for the system 
void menu() {
	cout << "1. Display Item List" << endl;
	cout << "2. Add Item List" << endl;
	cout << "3. Perform Transaction" << endl;
	cout << "4. Display Transaction History" << endl;
	cout << "5. Quit" << endl;
}

//--------------------- Start of Member 1 -------------------------------- 

//8. Function readUserDetails --> read (ifstream) all the users listed in "user.txt"  
//   and store the data into the respective parameters 
//   Hint: P1 is an array with row and column ([][4])  
//         and P3 should be reference parameter in this function 
void readUserDetails(string userDetails[][4], int& totalUsers) {

	ifstream inFile;
	inFile.open("user.txt");

	if (inFile.is_open()) {
		// store name, birthdate, gender then password into userDetails 
		while (!inFile.eof()) {
			getline(inFile, userDetails[totalUsers][0]);
			// account for empty bottom line in user.txt 
			if (userDetails[totalUsers][0] == "")
				break;
			getline(inFile, userDetails[totalUsers][1]);
			inFile >> userDetails[totalUsers][2] >> userDetails[totalUsers][3];
			inFile.ignore();
			totalUsers += 1;
		}

	}
	else {
		cout << "Warning: user.txt not found" << endl;
	}
	inFile.close();
}

//9. Function registerNewUser --> To register new user and save it to "user.txt" 
void registerNewUser() {
	string name, password, gender, birthdate;
	ofstream outFile;
	outFile.open("user.txt", ios::app);

	// get username 
	cout << "Username: ";
	getline(cin, name);

	// get password 
	cout << "Password: ";
	getline(cin, password);

	// get gender 
	cout << "Gender: ";
	getline(cin, gender);

	// get birthdate 
	cout << "Date Of Birth: ";
	getline(cin, birthdate);

	// save into user.txt with correct format 
	outFile << name << "\n";
	outFile << birthdate << "\n";
	outFile << gender << " ";
	outFile << password << "\n";

	outFile.close();
}

//10. Function login --> For user to login with the registered username and password 
//   Hint: P1 is an array with row and column ([][4]) 
//         and P2 should be reference parameter in this function 
int login(const string userDetails[][4], int totalUsers, string& userName) {

	//Use for loop to check whether the username and password can be found in the  
	//respective array or not  
	//Assign a value to be return using if...else statement to handle the conditions as mentioned in main function 
	//userName is referred back to the calling function if successfully login 
	//Cout "login() is not implemented" if the function is not implemented 

	bool found = false;
	int count = 0;
	string name, password;

	// input name and password 
	cout << "Username: ";
	getline(cin, name);

	cout << "Password: ";
	getline(cin, password);


	// loop until either find matching username and password or until no more users in userDetails left 
	while (!found and count < totalUsers) {
		if (userDetails[count][0] == name and userDetails[count][3] == password) {
			found = true;
			//update userName if found 
			userName = name;
		}
		else
			count += 1;
	}

	// return 0 if found or -1 if not found 
	if (!found)
		return -1;
	else
		return 0;
}

//--------------------- End of Member 1 -------------------------------- 
//--------------------- Start of Member 2 -------------------------------- 

//11. Function readItemList --> read (ifstream) all the items listed in "XX_itemList.txt"   
//    and store the data into the respective parameters 
//    Hint:  
//    1) P8 should be reference parameters in this function 
//    2) Create a new text file (using ofstream) for current login user if the item list text file does not exist 
//       E.g., you will need to create a text file named "John Lee Wei Kok_itemList.txt" for John Lee Wei Kok  
//       since the text file does not exist. It might be the user register but did not add items or the user is  
//       a new user without any record 
//    3) If the text file exists, read the records. E.g., "Karen Tan Wei Wei_itemList.txt" is available and  
//       the details are read and load into the respective parameters 
//    4) A global variable named "currentUser" is defined before function prototype 
//       "currentUser" stores the username that successfully login and can be used to create the new text file  
void readItemList(string items[], string codes[], double prices[], double weights[], int& totalItems) {
	// Function to read items from a user's shopping list file 
	string filename = currentUser + "_itemList.txt";	// Construct filename based on global variable currentUser 
	ifstream infile(filename);	// Open the user's item list file for reading 

	if (!infile.is_open()) {
		// If the file doesn't exist, create an empty file and close it. 
		ofstream outfile(filename);
		outfile.close();
	}

	// If the item list file exists 
	if (infile.is_open()) {
		// Check if the file open successfully and if it doesn�t exist create the file 
		totalItems = 0;	// Initialize the total number of items to zero. 
		while (!infile.eof()) {
			// Read items from the file line by line until the end of the file is reached. 
			getline(infile, items[totalItems]);
			if (items[totalItems] == "")
				break;
			getline(infile, codes[totalItems]);
			infile >> prices[totalItems] >> weights[totalItems];
			infile.ignore();	// Ignore any remaining characters on the current line. 
			totalItems++;	// Increment the total number of items read. 
		}
		infile.close();	// Close the file after reading all the items. 
	}
}

//12. Function addItemList --> add new items into the existing list  
//    The new item need to be updated in "XX_itemList.txt" as well 
//    Hint: P8 should be a reference parameter as the number of items should be updated 
void addItemList(string items[], string codes[], double prices[], double weights[], int& totalItems) {
	// Function to add a new item to the user's shopping list file. 

	  // Construct the filename based on a global variable storing the current user's name. 
	string filename = currentUser + "_itemList.txt";
	ofstream outfile(filename, ios::app);	// Open the user's item list file in append mode. 

	if (outfile.is_open()) {
		// Prompt the user to enter item details.
		int cont;
		cout << "Add new item? (1-yes, 2-no): ";
		cin >> cont;
		cin.ignore();
		while (cont == 1) {
			cout << "New item's name: ";
			getline(cin, items[totalItems]);	// Use getline to handle spaces in item names 
			cout << "New item's code: ";
			getline(cin, codes[totalItems]);
			cout << "Price of new item per KG (RM): ";
			cin >> prices[totalItems];
			cin.ignore();
			cout << "Purchasing Weight (KG): ";
			cin >> weights[totalItems];
			cin.ignore();
			// Write new item details to file to the end of the file. 
			outfile << fixed << setprecision(2) << items[totalItems] << endl << codes[totalItems] << endl << prices[totalItems] << " " << weights[totalItems] << endl;
			totalItems++;	// Increment the total number of items to reflect the new addition. 
			cout << "Add new item? (1-yes, 2-no): ";
			cin >> cont;
			cin.ignore();
		}

		outfile.close();	// Close the output file after writing the new item. 
	}
	else {
		cout << filename << "is not implemented." << endl;
		// Inform the user that the file cannot be opened for appending. 
	}
}

//13. Function displayItemList --> display the details of all the items in the list 
void displayItemList(string items[], string codes[], double prices[], double weights[], int totalItems) {
	// This function displays the user's shopping list from the item list file. 
	// Display a header for the item list table 
	for (int i = 0; i < totalItems; ++i) {
		// Loop through each item in the list and display its details 
		cout << fixed << setprecision(2) << "Item " << i+1 << endl << "Name: " << items[i] << endl << "Code: " << codes[i] << endl << "Price per KG: RM" << prices[i] << endl << "Purchasing Weight: " << weights[i] << "KG" << endl << endl;
	}
	system("pause");
}

//--------------------- End of Member 2 -------------------------------- //--------------------- Start of Member 3 -------------------------------- 

//14. Function readTransaction --> read (ifstream) all the items listed in "XX_transaction.txt"  
//    and store the data into the respective parameters 
//    Hint: 
//    1) P9 and P12 should be reference parameters in this function 
//    2) Create a new text file (using ofstream) for current login user if the transaction text file does not exist 
//       E.g., you will need to create a text file named "John Lee Wei Kok_transaction.txt" for John Lee Wei Kok  
//       since the text file does not exist. It might be the user registered but did not perform any transaction yet  
//       or the user is a new user without any transaction 
//    3) If the text file exists, read the records. E.g., "Karen Tan Wei Wei_transaction.txt" is available and  
//       the details are read and load into the respective parameters 
//    4) A global variable named "currentUser" is defined before function prototype 
//       "currentUser" stores the username that successfully login and can be used to create the new text file  
void readTransaction(double& totalAmountTransaction, string dates[], double amounts[], int& totalNumberTransactions) {
	// Name the file based on the current log in user  
	string fileName = currentUser + "_transaction.txt";

	//Declare file stream variable
	ifstream transactionFile;
	ofstream newTransactionFile;

	//Open the file 
	transactionFile.open(fileName);

	//If the transaction text file does not exist  
	if (!transactionFile.is_open())
	{
		//Create a new text file named based on the current log in user, then close the file  
		ofstream newTransactionFile(fileName);
		newTransactionFile.close();
	}

	//If the transaction text file exists  
	else
	{
		//Initialize the total number of transactions to zero
		totalNumberTransactions = 0;

		//Read the available balance (total amount of transaction) from the first line 
		transactionFile >> totalAmountTransaction;
		transactionFile.ignore();   // Ignore any remaining characters on the current line

		//Read dates and amounts line by line from the file 
		while (!transactionFile.eof())
		{
			//Update and store data into each parameter 
			transactionFile >> dates[totalNumberTransactions];
			if (dates[totalNumberTransactions] == "")
				break;
			transactionFile >> amounts[totalNumberTransactions];
			transactionFile.ignore();    // Ignore any remaining characters on the current line

			totalNumberTransactions++;   // Increment the total number of transactions
		}
		//Close the file  
		transactionFile.close();
	}
}

//15. Function transaction --> allow user to perform transaction with an amount and update in "XX_transaction.txt"  
//    Hint: P9 and P12 should be reference parameters in this function 
void transaction(double& totalAmountTransaction, string dates[], double amounts[], int& totalNumberTransactions) {

	//Declare variables to perform transaction  
	double amount;
	string date;

	//Allow user to perform transaction with an amount and a date 
	cout << "Available Balance: RM " << fixed << setprecision(2) << totalAmountTransaction << endl << endl;
	cout << "Amount of Transaction: RM ";
	cin >> amount;
	cout << "Date of Transaction: ";
	cin >> date;

	//Update the variable 
	totalAmountTransaction += amount;
	dates[totalNumberTransactions] = date;
	amounts[totalNumberTransactions] = amount;
	totalNumberTransactions++;

	// Name the file based on the current log in user
	string fileName = currentUser + "_transaction.txt";

	//Declare file stream variable
	ofstream newTransactionFile;

	//Open the text file created for the current login user  
	newTransactionFile.open(fileName);
	if (newTransactionFile.is_open())
	{
		//Write total amount of transaction into the file
		newTransactionFile << totalAmountTransaction << endl;
		newTransactionFile.close();   //Close the file
	}
	//Open the text file created for the current login user in append mode
	newTransactionFile.open(fileName, ios::app);
	if (newTransactionFile.is_open())
	{
		//Write dates and amounts of transaction into the file
		for (int i = 0; i < totalNumberTransactions; i++)
		{
			newTransactionFile << dates[i] << " " << amounts[i] << endl;
		}
		newTransactionFile.close();   //Close the file
	}

	//Variable to store user's choice (continue to perform transaction or exit)  
	int cont_performTransaction;

	//Ask the user whether want to continue transaction
	cout << "Continue? (1-yes, 2-no): ";
	cin >> cont_performTransaction;

	//If the user wants to continue transaction, clear the screen and return to the perform transaction screen, with updated available balance (total amount of transaction)
	if (cont_performTransaction == 1)
	{
		system("cls");
		transaction(totalAmountTransaction, dates, amounts, totalNumberTransactions);
	}
}

//16. Function displayTransactionDetails --> Display the available balance and also the history of related  
//    transaction for the current login user  
//    Able to detect whether it is a top up or it is a spending from the record 
void displayTransactionDetails(double& totalAmountTransaction, string dates[], double amounts[], int& totalNumberTransactions) {
	//Display a header for the total amount of transaction
	cout << "Available Balance: RM " << fixed << setprecision(2) << totalAmountTransaction << endl << endl;

	//Display transaction histories one by one, each with corresponding date and amount 
	for (int i = 0; i < totalNumberTransactions; i++)
	{
		cout << "Transaction " << i + 1 << endl;
		cout << "Date: " << dates[i] << endl;

		// Check whether the amount is positive (top up) or negative (spent)  
		if (amounts[i] > 0)
		{
			cout << "Top Up Amount: RM " << fixed << setprecision(2) << amounts[i] << endl;
		}
		else
		{
			cout << "Spent Amount: RM " << fixed << setprecision(2) << amounts[i] << endl;
		}
		cout << endl;
	}
	system("pause");
}


//--------------------- End of Member 3 -------------------------------- 


