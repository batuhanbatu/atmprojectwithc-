#include "Account.h"
int main()
{
	string name;
	long int accountNumber, accountNumber2;
	double balance, money;
	int operationNumber, accountType;
getName: cout << "Enter your name ";
	getline(cin,name);
	if (name == "")
	{
		cout << "Error! You should have entered a name\n";
		goto getName;
	}
	cout << "Enter your account number ";
	cin >> accountNumber;
	Account myobj1(accountNumber, name);
getAccounntType: cout << "Enter your account type:\n";
	cout << "1) Normal Account\n";
	cout << "2) Overdraft Account\n";
	cin >> accountType;
	if (accountType != 1 && accountType != 2)
	{
		cout << "Error! You should have entered a number as 1 or 2\n";
		goto getAccounntType;
	}
	OverdraftAccount overobj1;
menu:	cout << "Dear "<<name<<", enter the operation you want to do\n";
	cout << "1) Deposit\n";
	cout << "2) Withdraw\n";
	cout << "3) Get Balance\n";
	cout << "4) Money Transfer\n";
	cout << "5) Add Interest\n";
	cout << "6) Change to ";
	if (accountType == 1) cout << "Overdraft Account\n";
	else cout << "Normal Account\n";
	cout << "7) Exit\n";
	cin >> operationNumber;
	if (operationNumber == 1)
	{
		cout << "\nEnter the money you want to add into your account ";
		cin >> money;
		if (money < 0)
		{
			cout << "Error! You should have entered a positive number\n-------------------\n";
			goto menu;
		}
		cout << "Operation is completed and your new balance is " << myobj1.deposit(money) << "\n-------------------\n";
		goto menu;
	}
	if (operationNumber == 2)
	{
		cout << "\nEnter the money you want to withdraw from your account ";
		cin >> money;
		if (money < 0)
		{
			cout << "Error! You should have entered a positive number\n-------------------\n";
			goto menu;
		}
		if (money>myobj1.getBalance() && accountType==1)
		{
			cout << "Error! You can't withdraw money since it exceeds your account limit\n-------------------\n";
			goto menu;
		}
		if (money>myobj1.getBalance() && accountType == 2)
		{
			bool sure;
			cout << "I warn you, "<<name<<"! You are about to withdraw money from your Overdraft Account. You may be exposed to high interest rates. If you want to continue press 1, else please press 0\n";
			cout << "Your choice ";
			cin >> sure;
			if (sure)
			{
				cout << "Operation is completed and your new balance is " << overobj1.withDraw(money,myobj1) << "\n-------------------\n";
				goto menu;
			}
			cout << "-------------------\n";
			goto menu;
		}
		else
		{
			cout << "Operation is completed and your new balance is " << myobj1.withDraw(money) << "\n-------------------\n";
			goto menu;
		}
	}
	if (operationNumber == 3)
	{
		cout << "\nYour balance is " << myobj1.getBalance() << "\n-------------------\n";
		goto menu;
	}
	if (operationNumber == 4)
	{
		if (myobj1.getBalance() <= 0)
		{
			cout << "Error! Your account hasn't permission to transfer money since your balance is insufficient\n-------------------\n";
			goto menu;
		}
		cout << "\nEnter the MONEY you want to send to another account ";
		cin >> money;
		cout << "Enter the ACCOUNT NUMBER of the account you want to send money ";
		cin >> accountNumber2;
		if (money < 0)
		{
			cout << "Error! You should have entered a positive number\n-------------------\n";
			goto menu;
		}
		else
		{
			Account myobj2(accountNumber2,"");
			myobj1.moneyTransfer(myobj1, myobj2, money);
			cout << "-------------------\n";
			goto menu;
		}
	}
	if (operationNumber == 5)
	{
		cout << "\nOperation is completed and your new balance is " << myobj1.addInterest() << "\n-------------------\n";
		goto menu;
	}
	if (operationNumber == 6)
	{
		if (accountType == 1)
		{
			accountType = 2;
			cout << "\nYour account type has been changed to Overdraft Account successfully!\n-------------------\n";
			goto menu;
		}
		else
		{
			accountType = 1;
			cout << "\nYour account type has been changed to Normal Account successfully!\n-------------------\n";
			goto menu;
		}
	}
	if (operationNumber == 7) exit(0);
	else
	{
		cout << "Error! You should have entered a number range between 1 and 7\n-------------------\n";
		goto menu;
	}
	system("Pause");
	return 0;
}