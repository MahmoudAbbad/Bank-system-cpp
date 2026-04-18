#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
class clsUpdateCurrencyRateScreen : protected clsScreen
{
private : 

	static float _ReadRate()
	{
		float Rate;
		cout << "Enter New Rate: ";
		Rate = clsInputValidate::ReadFloatNumber();

		return Rate;
	}

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card : \n";
		cout << "\n----------------------\n\n";
		cout << "Country: " << Currency.Country() << endl;
		cout << "Code: " << Currency.CurrencyCode() << endl;
		cout << "Name: " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) =: " << Currency.Rate() << endl;
		cout << "\n----------------------\n\n";

	}

public : 

	static void ShowUpdateCurrencyRateScreen()
	{
		clsScreen::_DrawScreenHeader("Update Currency Screen");

		string CurrencyCode;
		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found , choose another currency: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
		_PrintCurrencyCard(Currency);

		char Answer = 'n';

		cout << "\n\nAre you sure you want to update the rate of this currency? y/n?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\nUpdate Currency Rate : \n";
			cout << "\n----------------------\n\n";

			Currency.UpdateRate(_ReadRate());
			cout << "\nCurrency Rate updated Successfully :-)";
			_PrintCurrencyCard(Currency);
		}
	}
};

