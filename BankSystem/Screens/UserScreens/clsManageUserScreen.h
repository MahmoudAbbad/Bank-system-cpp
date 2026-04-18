#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include <iomanip>
#include"clsBankClient.h";
#include"clsClientListScreen.h";
#include "clsAddNewClientScreen.h";
#include "clsDeleteClientScreen.h";
#include"clsUpdateClientScreen.h";
#include "clsFindClientScreen.h";
#include "clsTransactionScreen.h";
#include "clsListUsersScreen.h";
#include "clsAddNewUserScreen.h";
#include "clsDeleteUserScreen.h";
#include "clsUpdateUserScreen.h";
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUserScreen : protected clsScreen
{
	private:

		enum _enManageUserOption {
			eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
			eUpdateUser = 4, eFindUser = 5 , enGoBackToMainMenue
		};

		static short _ReadManageUserOption()
		{
			cout << setw(37) << left << "\t\t\t\t     Choose what do you want to do? [1 to 6]? ";
			short Choise = clsInputValidate::ReadIntNumberBetween(1, 6);
			return Choise;
		}

		static void _GoBackToManageMenueScreen()
		{
			cout << setw(37) << left << "\nPress any key to go back to manage menue screen...";
			system("pause>0");
			ShowManageUsersScreen();
		}

		static void _ShowAllUsersScreen()
		{
			clsListUsersScreen::ShowUsersList();
		}

		static void _ShowAddNewUserScreen()
		{
			clsAddNewUserScreen::ShowAddNewClientScreen();
		}

		static void _ShowDeleteUsersScreen()
		{
			//cout << "Show Delete User Screen Will be here...\n";
			clsDeleteUserScreen::ShowDeleteUserScreen();
		}

		static void _ShowUpdateUsersScreen()
		{
			//cout << "Show Update Users Screen Will be here...\n";
			clsUpdateUserScreen::ShowUpdateUserScreen();
		}

		static void _ShowFindClientsScreen()
		{
			//cout << "Show Find Users Screen Will be here...\n";
			clsFindUserScreen::ShowFindUserScreen();
		}

		static void _ShowTransactionsMenue()
		{
			clsTransactionScreen::ShowTransactionMenueScreen();
		}

		static void PerformManageUsersOption(_enManageUserOption ManageMenueOption)
		{
			switch (ManageMenueOption)
			{
			case clsManageUserScreen::eListUsers:
			{
				system("cls");
				_ShowAllUsersScreen();
				_GoBackToManageMenueScreen();
			}
			break;
			case clsManageUserScreen::eAddNewUser:
			{
				system("cls");
				_ShowAddNewUserScreen();
				_GoBackToManageMenueScreen();
			}
			break;
			case clsManageUserScreen::eDeleteUser:
			{
				system("cls");
				_ShowDeleteUsersScreen();
				_GoBackToManageMenueScreen();
			}
			break;
			case clsManageUserScreen::eUpdateUser:
			{
				system("cls");
				_ShowUpdateUsersScreen();
				_GoBackToManageMenueScreen();
			}
				break;
			case clsManageUserScreen::eFindUser:
			{
				system("cls");
				_ShowFindClientsScreen();
				_GoBackToManageMenueScreen();
			}
				break;
			}
		}

	public:

		static void ShowManageUsersScreen()
		{
			if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
			{
				return;
			}

			system("cls");

			clsScreen::_DrawScreenHeader("Manage Users Menue");

			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t\t\Manage Users Menue\n";
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t[1] Show Users List.\n";
			cout << setw(37) << left << "" << "\t[2] Add New User.\n";
			cout << setw(37) << left << "" << "\t[3] Delete User.\n";
			cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
			cout << setw(37) << left << "" << "\t[5] Find User.\n";
			cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
			cout << setw(37) << left << "" << "===========================================\n";

			PerformManageUsersOption(_enManageUserOption(_ReadManageUserOption()));
		}

};

