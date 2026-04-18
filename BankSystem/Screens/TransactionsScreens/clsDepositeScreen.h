#pragma once
#include<iostream>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";
using namespace std;
class clsDepositeScreen : protected clsScreen
{
private: 

	static void  _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card: \n";
		cout << "---------------------------";
		cout << "\nFirst Name : " << Client.FirstName;
		cout << "\nLast Name  : " << Client.LastName;
		cout << "\nFull Name  : " << Client.FullName();
		cout << "\nPhone      : " << Client.Phone;
		cout << "\nEmail      : " << Client.Email;
		cout << "\nA.Number   : " << Client.AccountNumber();
		cout << "\nPin Code   : " << Client.PinCode;
		cout << "\nA.Balance  : " << Client.AccountBalance;
		cout << "\n---------------------------\n";
	}

	static string _ReadAccountNumber()
	{
		cout << setw(28) << left << "Enter your Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}

public: 

	static void ShowDepositeScreen()
	{
		clsScreen::_DrawScreenHeader("Deposite Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not found.\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		
		double Amount = 0;
		cout << "\nPlease enter deposit amount? ";
		cin >> Amount;

		char Answer = 'n';
		cout << "\nAre you sure you want deposite " << Amount << " in your account? Y/N? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Client.Deposite(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance Is: " << Client.GetAccountBalance();
		}
		else
			cout << "\nOperation was cancelled.\n";

	}
};

