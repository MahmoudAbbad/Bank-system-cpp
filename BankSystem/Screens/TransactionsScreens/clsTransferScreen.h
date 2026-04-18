#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "clsScreen.h";
class clsTransferScreen : protected clsScreen
{
private: 

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\nClient Card: " << endl;
		cout << "\n-----------------------\n";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc.Number  : " << Client.AccountNumber();
		cout << "\nAcc.Balance :" << Client.AccountBalance;
		cout << "\n\n-----------------------\n";
	}

	static string _ReadAccountNumber()
	{
		cout << setw(28) << left << "\nEnter your Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}


public : 

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		
		_PrintClientCard(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
		
		_PrintClientCard(DestinationClient);

		float TransferAmount = _ReadAmount(SourceClient);

		char Answer = 'n';
		cout << "\nAre you sure you want to perform this operation? y/n?";
		cin >> Answer;

		if (toupper(Answer)=='Y')
		{
			if (SourceClient.Transfer(TransferAmount, DestinationClient))
				cout << "\nTransfer done successfully\n";
			else
				cout << "\nTransfer faild \n";
		}
		
		_PrintClientCard(SourceClient);
		_PrintClientCard(DestinationClient);
	}
};

