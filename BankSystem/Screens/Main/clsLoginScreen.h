#pragma once

#include <iostream>
#include "clsUser.h";
#include "Global.h";
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
using namespace std;

class clsLoginScreen : protected clsScreen
{
private:


	static bool _Login()
	{
		bool _LoginFaild = false;
		string UserName, Password;
		short _FaildLoginCount = 0;
	do
	{

		if (_LoginFaild)
		{
			_FaildLoginCount++;

			cout << "\nInvalid UserName/Password!";
			cout << "\nYou have " << (3-_FaildLoginCount) << " Trial(s) to login." << endl;
		}
		
		if(_FaildLoginCount == 3)
		{
			cout << "\nYou are Locked after 3 faild trails \n\n";
			return false;
		}

		cout << "\nUsername: ";
		UserName = clsInputValidate::ReadString();

		cout << "\nPassword: ";
		Password = clsInputValidate::ReadString();

		CurrentUser = clsUser::Find(UserName, Password);
		_LoginFaild = CurrentUser.IsEmpty();


	} while (_LoginFaild);
		
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenuScreen();
		return true;
	}

public: 

	static bool ShowLoginScreen() {


			system("cls");
			clsScreen::_DrawScreenHeader("Loging Screen");
			return _Login();
		
	}

};

