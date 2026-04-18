#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsUser.h";

class clsLoginRegesterScreen : protected clsScreen
{
private : 

	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
		cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
		cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
	}

public: 

	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}

		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecords = clsUser::GetLoginRegisterList();

		string Title = "Login Register List Screen";
		string SubTitle = "(" + to_string(vLoginRegisterRecords.size()) + ") Record(s).";

		_DrawScreenHeader(Title,SubTitle);

		cout<<setw(9)<<left<<""<<"\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(9) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLoginRegisterRecords.size() == 0)
			cout << "\t\t\t\tNo Logins Available In the System!";
		else

			for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecords)
			{
				_PrintLoginRegisterRecordLine(Record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}

};

