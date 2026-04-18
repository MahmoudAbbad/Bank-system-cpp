#pragma once
#include<iostream>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";

using namespace std;

class clsDeleteClientScreen : clsScreen
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

public: 
	
	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteuser))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("Delete Client Screen");

		string AccountNumber;

		cout << "Please enter account number: ";
		cin >> AccountNumber;

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThe client is not exist please enter correct accout number: ";
			cin >> AccountNumber;
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		char Answer = 'n';

		cout << "\nAre you sure you want to delete the client Y/N? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{

			if (Client.Delete())
			{
				cout << "\n\nAccount Deleted Successfully :-)\n";
			}

			else
			{
				cout << "\n\nError account was not saved becase it's Empty.";
			}

		}
	}


};

