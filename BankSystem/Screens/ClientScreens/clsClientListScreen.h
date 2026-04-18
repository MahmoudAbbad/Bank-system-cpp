#pragma once
#include <iostream>
#include "clsScreen.h";
#include<iomanip>
#include "clsBankClient.h";
#include "clsUtil.h";

const short EncryptKey = 5;

using namespace std;
class clsClientListScreen : protected clsScreen
{
private: 

	static void _PrintClientRecordList(clsBankClient Client)
	{
		cout << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << clsUtil::DecryptText(Client.PinCode,EncryptKey);
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}

public:

	static void ShowClientsList()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pListUser))
		{
			return;
		}


		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		double TotalBalances = clsBankClient::GetTotalBalances();
		string Title = "Client List Screen";
		string SubTitle = "( "+ to_string(vClients.size())+" ) Client(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n";

		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
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
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n";
	}

};

