#pragma warning(disable : 4996)

#include <iostream>
#include "clsUtil.h";
#include "clsDate.h";
#include "clsInputValidate.h";
#include "clsBankClient.h";
#include <cctype>
#include <iomanip>
#include <string>
#include "clsMainScreen.h";
#include "clsLoginScreen.h";
#include "clsScreen.h";
using namespace std;

int main() 
{
	
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
		
	}
	
	return 0;
}
