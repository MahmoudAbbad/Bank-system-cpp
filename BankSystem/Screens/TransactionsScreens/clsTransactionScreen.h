#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include <iomanip>
#include"clsBankClient.h";
#include "clsMainScreen.h";
#include "clsDepositeScreen.h";
#include "clsWithdrewScreen.h";
#include "clsTotalBalancesScreen.h";
#include "clsTransferScreen.h";
#include "clsTransferLogScreen.h";
using namespace std;

class clsTransactionScreen : protected clsScreen 
{
	private:

		enum _enTransactionMenueOption {
			eDeposite = 1, eWithDrew = 2, eTotalBalances = 3,eTransfer = 4,eTransferLog = 5,
			eGoBackToMainMenue = 6 
		};

		static short _ReadTransationMenueOption()
		{
			cout << setw(37) << left << "\t\t\t\t     Choose what do you want to do? [1 to 6]? ";
			short Choise = clsInputValidate::ReadIntNumberBetween(1, 6);
			return Choise;
		}

		static void _ShowDepositeScreen()
		{
			clsDepositeScreen::ShowDepositeScreen();
		}

		static void _ShowWithDrewScreen()
		{
			clsWithdrewScreen::ShowWithdrawScreen();
		}

		static void _ShowTotalBalancesScreen()
		{
			clsTotalBalancesScreen::ShowTotalBalancesScreen();
		}

		static void _ShowTransferScreen()
		{
			clsTransferScreen::ShowTransferScreen();
		}

		static void _ShowTransferLogScreen()
		{
			clsTransferLogScreen::ShowTransferLogScreen();
		}

		static void _PerformTransactionMenueOption(_enTransactionMenueOption TransactionMenueOption)
		{
			switch (TransactionMenueOption)
			{
			case clsTransactionScreen::eDeposite:
			{
				system("cls");
				_ShowDepositeScreen();
				_GoBackToTransactionMenue();
			}
				break;
			case clsTransactionScreen::eWithDrew:
			{
				system("cls");
				_ShowWithDrewScreen();
				_GoBackToTransactionMenue();
			}
				break;
			case clsTransactionScreen::eTransfer:
			{
				system("cls");
				_ShowTransferScreen();
				_GoBackToTransactionMenue();
			}
			break;
			case clsTransactionScreen::eTransferLog:
			{
				system("cls");
				_ShowTransferLogScreen();
				_GoBackToTransactionMenue();
			}
			break;
			case clsTransactionScreen::eTotalBalances:
			{
				system("cls");
				_ShowTotalBalancesScreen();
				_GoBackToTransactionMenue();
			}
				break;
			}
		}

		static void _GoBackToTransactionMenue()
		{
			cout << setw(37) << left << "\nPress any key to go back to Transaction menue screen...";
			system("pause>0");
			ShowTransactionMenueScreen();
		}

	public:

		static void ShowTransactionMenueScreen()
		{
			if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
			{
				return;
			}

			system("cls");
			clsScreen::_DrawScreenHeader("Trannsactions Screen");

			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t\t\Transaction Menue\n";
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t[1] Deposite.\n";
			cout << setw(37) << left << "" << "\t[2] Withdrew.\n";
			cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
			cout << setw(37) << left << "" << "\t[4] Transfer.\n";
			cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
			cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
			cout << setw(37) << left << "" << "===========================================\n";

			_PerformTransactionMenueOption(_enTransactionMenueOption(_ReadTransationMenueOption()));
		}
};