#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
using namespace std;
class clsCurrencyCalculatorScreen : protected clsScreen
{
private : 

	static clsCurrency _GetCurrency(string Massage)
	{
		string CurrencyCode;
		cout << Massage << endl;

		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found , choose another currency: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		return clsCurrency::FindByCurrencyCode(CurrencyCode);
	}

	static float _ReadAmount()
	{
		float Amount;
		cout << "\nEnter Amount to Exchange: ";
		Amount = clsInputValidate::ReadFloatNumber();

		return Amount;
	}

	static void _PrintCurrencyCard(clsCurrency Currency , string Title = "Currency Card")
	{ 
		cout << "\n" << Title << endl;
		cout << "\n----------------------\n\n";
		cout << "Country: " << Currency.Country() << endl;
		cout << "Code: " << Currency.CurrencyCode() << endl;
		cout << "Name: " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) =: " << Currency.Rate() << endl;
		cout << "\n----------------------\n\n";

	}

	static void _PrintCalculationResults(float Amount , clsCurrency Currency1 , clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1, "Currency From: ");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConvertin From USD to : \n";

		_PrintCurrencyCard(Currency2, "To : ");

		float AmountIncurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.CurrencyCode() 
			<< " = " << AmountIncurrency2 << " " << Currency2.CurrencyCode() << endl;

	}

public : 

	static void ShowCurrencyCalaculatorScreen()
	{
		char Continue = 'n';

		do 
		{
			system("cls");
			clsScreen::_DrawScreenHeader("Currency Calculator Screen");
			
			clsCurrency CurrencyFrom = _GetCurrency("Please Enter Currrency 1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("Please Enter Currrency 2 Code: ");

			float Amount = _ReadAmount();

			_PrintCalculationResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\nDo you want to perform another operation? y/n? ";
			cin >> Continue;
		
		} while(toupper(Continue) == 'Y');
	}

};

