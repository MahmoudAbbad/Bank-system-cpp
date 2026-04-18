#pragma once
#include<iostream>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";

using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private: 

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

	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewUser))
		{
			return;
		}


		clsScreen::_DrawScreenHeader("Add New Client Screen");

		string AccountNumber;

		cout << "Please enter account number: ";
		cin >> AccountNumber;

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThe client is already exist please enter another account number: ";
			cin >> AccountNumber;

			clsBankClient Client = clsBankClient::Find(AccountNumber);
		}

		clsBankClient NewClient = clsBankClient::GetNewClientObject(AccountNumber);

		cout << "\nAdd New Client :\n";
		cout << "-----------------\n";

		_ReadClientInfo(NewClient);
		NewClient.Save();

		clsBankClient::enSaveResults  SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject:
		{
			cout << "\n\nError account was not saved becase it's Empty.";
		}
		break;
		case clsBankClient::svSucceeded:
		{
			cout << "\n\nAccount added Successfully :-)\n";
			_PrintClient(NewClient);
		}
		break;
		case clsBankClient::svFaildAccountNumberExist:
		{
			cout << "\n\nError account was not saved becase it's already exist.";
		}
		}
	}


};

