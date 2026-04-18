#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include <vector>
#include"clsPerson.h";
#include"clsString.h";
#include "clsScreen.h";
const string FileName = "Clients.txt";
class clsBankClient : public clsPerson
{
private:

	enum _enMode { EmptyMode = 0, UpdateMode = 1, AddNewClient = 2, DeleteClient = 3 };
	_enMode _Mode;

	
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#")
	{
		vector <string> vClinetRecord;
		vClinetRecord = clsString::SplitString(Line, Separator);

		return clsBankClient(_enMode::UpdateMode, vClinetRecord[0], vClinetRecord[1], vClinetRecord[2],
			vClinetRecord[3], vClinetRecord[4], vClinetRecord[5], stod(vClinetRecord[6]));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(_enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsBankClient _ConvertLineToData(string Str, string Separator = "#//#")
	{
		clsBankClient Client = _GetEmptyClientObject();
		vector <string> vString = clsString::SplitString(Str, Separator);

		Client._Mode = _enMode::UpdateMode;
		Client.FirstName = vString[0];
		Client.LastName = vString[1];
		Client.Email = vString[2];
		Client.Phone = vString[3];
		Client._AccountNumber = vString[4];
		Client.PinCode = vString[5];
		Client.AccountBalance = stod(vString[6]);

		return Client;
	}

	static vector <clsBankClient> _LoadClientsDataFromFileToVector()
	{
		vector <clsBankClient> vClients;
		string Line;

		fstream MyFile;
		MyFile.open(FileName, ios::in); // ReadMode

		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				vClients.push_back(_ConvertLineToData(Line));
			}

			MyFile.close();
		}
		return vClients;
	}

	string _ConvertRecordsToLine(clsBankClient Client)
	{
		return Client.FirstName + "#//#" + Client.LastName + "#//#" + Client.Email + "#//#" + Client.Phone + +"#//#" +
			Client._AccountNumber + "#//#" + Client.PinCode + "#//#" + to_string(Client.AccountBalance);
	}

	void _SaveCurrentObject(clsBankClient& C)
	{
		C.FirstName = FirstName;
		C.LastName = LastName;
		C.AccountBalance = AccountBalance;
		C.Email = Email;
		C.Phone = Phone;
		C.PinCode = PinCode;
	}

	void _SaveClientsToFile(vector <clsBankClient> _vClients)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out);

		if (MyFile.is_open())
		{
			for (clsBankClient& C : _vClients)
			{
				if (C.MarkForDelete() == false)
				{
					MyFile << _ConvertRecordsToLine(C) << endl;
				}
			}
		}
		MyFile.close();
	}

	void _AddDataLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFileToVector();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				_SaveCurrentObject(C);
				break;
			}
		}

		_SaveClientsToFile(_vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertRecordsToLine(*this));
	}

	string _PrepareTransferLogRecord(clsBankClient DirectionClient, float Amount, string Seperator = "#//#")
	{
		string TransferRecord = "";

		TransferRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferRecord += AccountNumber() + Seperator;
		TransferRecord += DirectionClient.AccountNumber() + Seperator;
		TransferRecord += to_string(Amount) + Seperator;
		TransferRecord += to_string(AccountBalance) + Seperator;
		TransferRecord += to_string(DirectionClient.AccountBalance) + Seperator;
		TransferRecord += CurrentUser.UserName;

		return TransferRecord;
	}

	void _RegisterTransferLog(clsBankClient DirectionClient, float Amount)
	{
		string stDataLine = _PrepareTransferLogRecord(DirectionClient, Amount);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertRegisterTransferLineToRecord(string Line , string Separator = "#//#")
	{
		vector <string> vTransferRecord = clsString::SplitString(Line , "#//#");
		stTransferLogRecord TransferLogRecord;

		TransferLogRecord.DateTime = vTransferRecord[0];
		TransferLogRecord.SorceClient = vTransferRecord[1];
		TransferLogRecord.DirectionClient = vTransferRecord[2];
		TransferLogRecord.Amount = stof(vTransferRecord[3]);
		TransferLogRecord.FirstAccountBalance = stof(vTransferRecord[4]);
		TransferLogRecord.SecondAccountBalance = stof(vTransferRecord[5]);
		TransferLogRecord.UserName = vTransferRecord[6];

		return TransferLogRecord;
	}

public: 

	struct stTransferLogRecord {

		string DateTime;
		string SorceClient;
		string DirectionClient;
		float Amount;
		float FirstAccountBalance;
		float SecondAccountBalance;
		string UserName;
	};

	clsBankClient(_enMode Mode , string FirstName , string LastName , string Email , string Phone
		, string AccountNumber , string PinCode , float AccountBalance) : clsPerson(FirstName , LastName , Email , Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;

	}

	 bool IsEmpty()
	{
		return (_Mode == _enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}
	
	__declspec(property(get = GetPinCode , put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void setMarkForDelete(bool Mark)
	{
		_MarkForDelete = Mark;
	}

	bool MarkForDelete()
	{
		return _MarkForDelete;
	}

	static clsBankClient Find(string AccountNumber)
	{
		string Line;
		//vector <clsBankClient> Clients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				//Clients.push_back(Client);
			}

			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber , string PinCode)
	{
		string Line;
		//vector <clsBankClient> Clients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
				//Clients.push_back(Client);
			}

			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);
		return !Client.IsEmpty();
	}

	enum enSaveResults{svFaildEmptyObject =0 , svSucceeded=1 , svFaildAccountNumberExist = 2};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case _enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}
		
		case _enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}
		case _enMode::AddNewClient:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return clsBankClient::enSaveResults::svFaildAccountNumberExist;
			}
			else {

				_AddNew();
				_Mode = _enMode::UpdateMode;
				return clsBankClient::enSaveResults::svSucceeded;
			}
		}
		}

	}

	static clsBankClient GetNewClientObject(string AccountNumber)
	{
		return clsBankClient(_enMode::AddNewClient, "", "", "", "", AccountNumber, "", 0);
	}
	
	bool Delete()
	{
		vector<clsBankClient> vClients = _LoadClientsDataFromFileToVector();

		fstream MyFile;
		MyFile.open(FileName, ios::in);

		if (MyFile.is_open())
		{
			for (clsBankClient& C : vClients)
			{
				if (C.AccountNumber() == _AccountNumber)
				{
					C._MarkForDelete = true;
					MyFile.close();
					break;
				}
			}
			MyFile.close();
		}

		_SaveClientsToFile(vClients);
		*this = _GetEmptyClientObject();

		return true;
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFileToVector();
	}

	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFileToVector();
		double TotalBalances =0;
		for (clsBankClient Client : vClients)
		{
			TotalBalances += Client.AccountBalance;
		}

		return TotalBalances;
	}

	 void Deposite(double Amount)
	{
		AccountBalance += Amount;
		Save();
	}

	 bool Withdraw(double Amount)
	 {
		 if (Amount > _AccountBalance)
		 {
			 return false;
		}
		 else
		 {
			 AccountBalance -= Amount;
			 Save();
			 return true;
		 }
	 }

	 bool Transfer(float Amount, clsBankClient& DestinationClient)
	 {

		 if (Amount>AccountBalance)
		 {
			 return false;
		 }

		Withdraw(Amount);
		DestinationClient.Deposite(Amount);
		_RegisterTransferLog(DestinationClient, Amount);
		return true;


	 }

	 static vector<stTransferLogRecord> GetTransferLogRecords()
	 {
		 vector <stTransferLogRecord> vTransferLogRecords;

		 fstream MyFile;
		 MyFile.open("TransferLog.txt", ios::in);


		 if (MyFile.is_open())
		 {
			 stTransferLogRecord TransferLogRecord;
			 string Line;

			 while (getline(MyFile, Line))
			 {
				 TransferLogRecord = _ConvertRegisterTransferLineToRecord(Line);

				 vTransferLogRecords.push_back(TransferLogRecord);
			 }
		 }
		 MyFile.close();

		 return vTransferLogRecords;
	 }

};