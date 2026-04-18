#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h";
#include "clsScreen.h";
class clsCurrenciesListScreen :protected clsScreen
{
private: 

	static void _PrintCurrencyRecordList(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << left << setw(8) << Currency.CurrencyCode();
		cout << "| " << left << setw(45) << Currency.CurrencyName();
		cout << "| " << left << setw(20) << Currency.Rate();
	}

public : 

	static void ShowCurrenciesList()
	{
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
		string Title = "Currency List Screen";
		string SubTitle = "( " + to_string(vCurrencies.size()) + " ) Currency(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n\n";

		cout << setw(8) << left << "" << "| " << setw(30) << left << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(20) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n\n";

		if (vCurrencies.size() == 0)
		{
			cout << "\t\t\t\tNo Currencies Available In the System!";
		}
		else
		{
			for (clsCurrency& C : vCurrencies)
			{
				_PrintCurrencyRecordList(C);
				cout << endl;
			}
		}
		cout << "\t_______________________________________________________";
		cout << "______________________________________________\n";
	}

};

