#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsListCurrencyScreen.h";
#include "clsFindCurrencyScreen.h";
#include "clsUpdateCurrencyRateScreen.h";
#include "clsCurrencyCalculatorScreen.h";
using namespace std;
class clsCurrencyExchangeScreen : protected clsScreen
{
private: 

	enum _enCurrancyExchangeMenue{ListCurrencies = 1 , FindCurrency=2 , UpdateRate=3 , CurrencyCalculator = 4};

	static short _ReadCurrancyMenueOption()
	{
		cout << setw(37) << left << "\t\t\t\t     Choose what do you want to do? [1 to 5]? ";
		short Choise = clsInputValidate::ReadIntNumberBetween(1, 5);
		return Choise;
	}

	static void _ShowListCurrenciesScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesList();
	}

	static void _ShowFindCurrecyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrecyScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrecyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalaculatorScreen();
	}

	static void _GoBackToCurrencyExchangeMenue()
	{
		cout << "\nPress any key to go back to Currencies Menue...";
		system("pause>0");
		ShowCurrencciesMenue();
	}

	static void _PerformCurrencyExchangeOption(_enCurrancyExchangeMenue CurrencyExchangeOption)
	{
		switch (CurrencyExchangeOption) {

		case _enCurrancyExchangeMenue::ListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenue();
		}
		break;
		case _enCurrancyExchangeMenue::FindCurrency:
		{
			system("cls");
			_ShowFindCurrecyScreen();
			_GoBackToCurrencyExchangeMenue();
		}
		break;
		case _enCurrancyExchangeMenue::UpdateRate:
		{
			system("cls");
			_ShowUpdateCurrecyScreen();
			_GoBackToCurrencyExchangeMenue();
		}
		break;
		case _enCurrancyExchangeMenue::CurrencyCalculator:
		{
			system("cls");
			_ShowCurrecyCalculatorScreen();
			_GoBackToCurrencyExchangeMenue();
		}
		break;
		}
	}

public : 

	static void ShowCurrencciesMenue()
	{

			system("cls");

			clsScreen::_DrawScreenHeader("Currancy Exchange Main Screen");

			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t\t\Currency Exhange Menue\n";
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
			cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
			cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
			cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
			cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
			cout << setw(37) << left << "" << "===========================================\n";

			_PerformCurrencyExchangeOption(_enCurrancyExchangeMenue(_ReadCurrancyMenueOption()));

	}
};

