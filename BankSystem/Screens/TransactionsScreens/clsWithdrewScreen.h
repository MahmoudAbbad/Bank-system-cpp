#pragma once
#include<iostream>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";
#include "iomanip";
using namespace std;
class clsWithdrewScreen : protected clsScreen
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

		static void ShowWithdrawScreen()
		{
			clsScreen::_DrawScreenHeader("Withdrew Screen");

			string AccountNumber = _ReadAccountNumber();

			while (!clsBankClient::IsClientExist(AccountNumber))
			{
				cout << "\nClient with [" << AccountNumber << "] does not found.\n";
				AccountNumber = _ReadAccountNumber();
			}

			clsBankClient Client = clsBankClient::Find(AccountNumber);
			_PrintClient(Client);

			double Amount = 0;
			cout << "\nPlease enter withdrew amount? ";
			cin >> Amount;

			char Answer = 'n';
			cout << "\nAre you sure you want to perform this transaction? Y/N? ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{
				if (Client.Withdraw(Amount))
				{
					cout << "\nAmount Deposited Successfully.\n";
					cout << "\nNew Balance Is: " << Client.GetAccountBalance();
				}
				else
				{
					cout << "\nCannot withdraw, Insuffecient Balance!\n";
					cout << "\nAmount to withdraw is: " << Amount << endl;
					cout << "Your Balance is: " << Client.AccountBalance << endl;
				}
			}
			else
				cout << "\nOperation was cancelled.\n";

		}

};

