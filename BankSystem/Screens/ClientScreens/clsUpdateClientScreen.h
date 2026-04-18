#pragma once
#include<iostream>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";

using namespace std;
class clsUpdateClientScreen : clsScreen
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

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}

public: 
	static void ShowUpdateClinetScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateUser))
		{
			return;
		}


		clsScreen::_DrawScreenHeader("Update Client Screen");

		string AccountNumber;

		cout << "Please enter account number: ";
		cin >> AccountNumber;

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		while (Client.IsEmpty())
		{
			cout << "\nThe client is not exist please enter correct accout number: ";
			cin >> AccountNumber;

			clsBankClient Client = clsBankClient::Find(AccountNumber);
		}

		_PrintClient(Client);

		cout << "\nUpdate client :\n";
		cout << "-----------------\n";

		_ReadClientInfo(Client);

		clsBankClient::enSaveResults  SaveResult;

		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject:
		{
			cout << "\nError account was not saved becase it's Empty.";
		}
		break;
		case clsBankClient::svSucceeded:
		{
			_PrintClient(Client);
			cout << "\nAccount Updated Successfully :-)\n";
		}
		break;


		}
	}
};