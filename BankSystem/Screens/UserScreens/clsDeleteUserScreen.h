#pragma once
#include<iostream>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";
#include "clsUser.h"
using namespace std;

class clsDeleteUserScreen : clsScreen 
{
	private:

		static void  _PrintUser(clsUser User)
		{
			cout << "\nUser Card: \n";
			cout << "---------------------------";
			cout << "\nFirst Name : " << User.FirstName;
			cout << "\nLast Name  : " << User.LastName;
			cout << "\nFull Name  : " << User.FullName();
			cout << "\nPhone      : " << User.Phone;
			cout << "\nEmail      : " << User.Email;
			cout << "\nPermissions  : " << User.Permissions;
			cout << "\n---------------------------\n";
		}

	public:

		static void ShowDeleteUserScreen()
		{
			clsScreen::_DrawScreenHeader("Delete User Screen");

			string UserName;

			cout << "Please enter User Name: ";
			cin >> UserName;

			while (!clsUser::IsUserExist(UserName))
			{
				cout << "\nThe User is not exist please enter correct UserName: ";
				cin >> UserName;
			}

			clsUser User = clsUser::Find(UserName);

			_PrintUser(User);

			char Answer = 'n';

			cout << "\nAre you sure you want to delete the user Y/N? ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{

				if (User.Delete())
				{
					cout << "\n\nUser Deleted Successfully :-)\n";
				}

				else
				{
					cout << "\n\nError, User was not saved becase it's Empty.";
				}

			}
		}


};

