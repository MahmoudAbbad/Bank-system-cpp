#pragma once
#include<iostream>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";

using namespace std;

class clsFindClientScreen :protected clsScreen
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

	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindUser))
		{
			return;
		}

		string AccountNumber;

		clsScreen::_DrawScreenHeader("Find Client Screen");

		cout << "\nPlease enter account number: ";
		AccountNumber = clsInputValidate::ReadString();

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		while (Client.IsEmpty())
		{
			cout << "\nThe client is not exist please enter correct accout number: ";
			cin >> AccountNumber;
			Client = clsBankClient::Find(AccountNumber);
		}
		cout << "\nClient Found :-)\n";
			_PrintClient(Client);
		
	}


};

