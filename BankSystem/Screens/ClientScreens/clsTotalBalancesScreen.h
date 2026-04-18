#pragma once
#include<iostream>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";
#include "iomanip";
using namespace std;
class clsTotalBalancesScreen : protected clsScreen
{
private: 
	
	static void _PrintClientRecordList(clsBankClient Client)
	{
		cout << "\t\t| " << setw(15) << left << Client.AccountNumber();
		cout << "\t\t| " << setw(20) << left << Client.FullName();
		cout << "\t\t| " << setw(12) << left << Client.AccountBalance;
	}

public: 

	static void ShowTotalBalancesScreen()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		double TotalBalances = clsBankClient::GetTotalBalances();
		string Title = "Balances List Screen";
		string SubTitle = "( " + to_string(vClients.size()) + " ) Client(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t_______________________________________________";
		cout << "_________________________________________\n";

		cout << "\t\t| " << left << setw(15) << "Account Number";
		cout << "\t\t| " << left << setw(20) << "Client Name";
		cout << "\t\t| " << left << setw(12) << "Balance";
		cout << "\n\t_______________________________________________";
		cout << "_________________________________________\n";

		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tNo Clients Available In the System!";
		}
		else
		{
			for (clsBankClient& Client : vClients)
			{
				_PrintClientRecordList(Client);
				cout << endl;
			}
		}
		cout << "\n\t_______________________________________________";
		cout << "_________________________________________\n";
		cout << "\n\t\t\t\t  Total Balances = " << TotalBalances << endl;
		cout << "\n\t\t\t  ( " << clsUtil::NumberToText(TotalBalances)<<" )" << endl;
	
	}

};

