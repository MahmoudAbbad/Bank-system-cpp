#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include <iomanip>
#include "clsBankClient.h";
#include "clsClientListScreen.h";
#include "clsAddNewClientScreen.h";
#include "clsDeleteClientScreen.h";
#include "clsUpdateClientScreen.h";
#include "clsFindClientScreen.h";
#include "clsTransactionScreen.h";
#include "clsManageUserScreen.h";
#include "Global.h";
#include "clsLoginRegesterScreen.h";
#include "clsCurrencyExchangeScreen.h";
using namespace std;

class clsMainScreen : protected clsScreen
{
private : 

	enum _enMainMenueOption {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7 , eLoginRegister =8,CurrencyExchange =9, eExit = 10
	};


	static short _ReadMainMenueOption()
	{
		cout << setw(37)<< left << "\t\t\t\t     Choose what do you want to do? [1 to 10]? ";
		short Choise = clsInputValidate::ReadIntNumberBetween(1, 10);
		return Choise;
	}

	static void _GoBackToMainMenueScreen()
	{
		cout << setw(37) << left << "\nPress any key to go back to main menue screen...";
		system("pause>0");
		ShowMainMenuScreen();
	}

	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowClientsList();
	}
	
	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}
	
	static void _ShowDeleteClientsScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientsScreen()
	{
		clsUpdateClientScreen::ShowUpdateClinetScreen();
	}

	static void _ShowFindClientsScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenue()
	{
		clsTransactionScreen::ShowTransactionMenueScreen();
	}

	static void _ShowManageUsersMenue()
	{
		clsManageUserScreen::ShowManageUsersScreen();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegesterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		clsCurrencyExchangeScreen::ShowCurrencciesMenue();
	}

	static void _ShowEndScreen()
	{
		//cout << "\nEnd Screen Will be here...\n";
		_Logout();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static void PerformMainMenueOption(_enMainMenueOption MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case clsMainScreen::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenueScreen();
		}
		break;
		case clsMainScreen::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenueScreen();
		}
		break;
		case clsMainScreen::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientsScreen();
			_GoBackToMainMenueScreen();
		}
		break;
		case clsMainScreen::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientsScreen();
			_GoBackToMainMenueScreen();
		}
		break;
		case clsMainScreen::eFindClient:
		{
			system("cls");
			_ShowFindClientsScreen();
			_GoBackToMainMenueScreen();
		}
		break;
		case clsMainScreen::eShowTransactionsMenue:
		{
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenueScreen();
		}
		break;
		case clsMainScreen::eManageUsers:
		{
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenueScreen();
		}
		break;
		case clsMainScreen::CurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenueScreen();
		}
		break;
		case clsMainScreen::eLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenueScreen();
		}
		break;
		case clsMainScreen::eExit:
		{
			system("cls");
			_ShowEndScreen();
		}
		break;
		}
	}

public: 

	static void ShowMainMenuScreen()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("Main Menue");
		
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		PerformMainMenueOption(_enMainMenueOption(_ReadMainMenueOption()));
	}

	
};

