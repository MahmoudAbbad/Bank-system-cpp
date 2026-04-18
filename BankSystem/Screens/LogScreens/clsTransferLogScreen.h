#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h";
class clsTransferLogScreen : protected clsScreen
{
private: 

	static void _PrintRegisterTransferRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
	{
		cout << setw(9) << left << "" << "| " << setw(25) << left << TransferLogRecord.DateTime;
		cout << "| " << setw(10) << left << TransferLogRecord.SorceClient;
		cout << "| " << setw(10) << left << TransferLogRecord.DirectionClient;
		cout << "| " << setw(10) << left << TransferLogRecord.Amount;
		cout << "| " << setw(10) << left << TransferLogRecord.FirstAccountBalance;
		cout << "| " << setw(10) << left << TransferLogRecord.SecondAccountBalance;
		cout << "| " << setw(10) << left << TransferLogRecord.UserName;
	}

public: 
	 
	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLogRecord> vTransferLogRecords = clsBankClient::GetTransferLogRecords();

		string Title = "Transfer Log Screen";
		string SubTitle = "(" + to_string(vTransferLogRecords.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(9) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(9) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(10) << "s.Acct";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(10) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vTransferLogRecords.size() == 0)
			cout << "\t\t\t\tNo Logins Available In the System!";
		else

			for (clsBankClient::stTransferLogRecord Record : vTransferLogRecords)
			{
				_PrintRegisterTransferRecordLine(Record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

};

