#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
class clsAddNewUserScreen : protected clsScreen
{
private : 

	static void _ReadUserInfo(clsUser& User)
	{
		
		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions: ";
		User.Permissions = _ReadPermissionsToSet();

	}

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}
	
	static short _ReadPermissionsToSet()
	{
		short _Permissions = 0;
		char _Answer = 'n';

		cout << "\n\nDo u want to give full access? y/n? ";
		cin >> _Answer;

		if (_Answer == 'Y' || _Answer == 'y')
		{
			return -1;
		}

		cout << "\nDo u want to give access to : \n";

		cout << "\nShow Client List? y/n? ";
		cin >> _Answer;

		if (_Answer == 'Y' || _Answer == 'y')
		{
			_Permissions += clsUser::enPermissions::pListUser;
		}
	
		cout << "\nAdd New Client? y/n? ";
		cin >> _Answer;

		if (_Answer == 'Y' || _Answer == 'y')
		{
			_Permissions += clsUser::enPermissions::pAddNewUser;
		}
		
		cout << "\nDelete Client? y/n? ";
		cin >> _Answer;

		if (_Answer == 'Y' || _Answer == 'y')
		{
			_Permissions += clsUser::enPermissions::pDeleteuser;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> _Answer;

		if (_Answer == 'Y' || _Answer == 'y')
		{
			_Permissions += clsUser::enPermissions::pUpdateUser;
		}

		cout << "\nFind Client? y/n? ";
		cin >> _Answer;

		if (_Answer == 'Y' || _Answer == 'y')
		{
			_Permissions += clsUser::enPermissions::pFindUser;
		}

		cout << "\nTransactions? y/n? ";
		cin >> _Answer;

		if (_Answer == 'Y' || _Answer == 'y')
		{
			_Permissions += clsUser::enPermissions::pTransactions;
		}

		cout << "\nManage Users? y/n? ";
		cin >> _Answer;

		if (_Answer == 'Y' || _Answer == 'y')
		{
			_Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nShow Login Register List? y/n? ";
		cin >> _Answer;

		if (_Answer == 'Y' || _Answer == 'y')
		{
			_Permissions += clsUser::enPermissions::pLoginRegister;
		}

		return _Permissions;

	}

public : 

	static void ShowAddNewClientScreen()
	{
		clsScreen::_DrawScreenHeader("Add New User Screen");

		string UserName;

		cout << "Please enter UserName: ";
		cin >> UserName;

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nThe client is already exist please enter another UserName: ";
			cin >> UserName;

			clsUser User = clsUser::Find(UserName);
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		cout << "\nAdd New User :\n";
		cout << "-----------------\n";

		_ReadUserInfo(NewUser);
		NewUser.Save();

		clsUser::enSaveResults  SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::svFaildEmptyObject:
		{
			cout << "\n\nError account was not saved becase it's Empty.";
		}
		break;
		case clsUser::svSucceeded:
		{
			cout << "\n\nAccount added Successfully :-)\n";
			_PrintUser(NewUser);
		}
		break;
		case clsUser::svFaildUserExists:
		{
			cout << "\n\nError account was not saved becase it's already exist.";
		}
		}
	}



};

