#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
class clsFindCurrencyScreen : protected clsScreen
{
private : 

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

	static void _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\n\nCurrency Found :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
			cout << "\n\nCurrency Was NOT Found :-(\n";
	}

public : 

	static void ShowFindCurrencyScreen()
	{
		clsScreen::_DrawScreenHeader("Find Currency Screen");

		short Answer; 

		cout << "\nFind By [1] Code or [2] Country? ";
		cin >> Answer;

		if(Answer == 1)
		{
	
			string CurrencyCode;

			cout << "\nPlease Enter Currency Code? ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
			_PrintCurrencyCard(Currency);
			
		}
		else if(Answer ==2)
		{
			string CurrencyName;

			cout << "\nPlease Enter Currency Name? ";
			cin >> CurrencyName;

			clsCurrency Currency = clsCurrency::FindByCurrencyName(CurrencyName);
			_PrintCurrencyCard(Currency);
		}
	}
};

