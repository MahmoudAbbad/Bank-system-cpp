#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "clsString.h";
class clsCurrency
{
private: 
	enum _enMode {EmptyMode = 0 , UpdateMode = 1};

	_enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	
	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separator = "#//#")
	{
		vector <string> vCurrencyRecord;
		vCurrencyRecord = clsString::SplitString(Line, Separator);

		return clsCurrency(_enMode::UpdateMode, vCurrencyRecord[0], vCurrencyRecord[1], vCurrencyRecord[2],
			stof(vCurrencyRecord[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency , string Separator = "#//#")
	{
		string Line ="";

		Line += Currency.Country() + Separator;
		Line += Currency.CurrencyCode() + Separator;
		Line += Currency.CurrencyName() + Separator;
		Line += to_string(Currency.Rate());

		return Line;
	}

	static vector <clsCurrency> _LoadCurrencysDataFromFile()
	{
		vector <clsCurrency> vCurrency;
		string Line;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in); // ReadMode

		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				vCurrency.push_back(_ConvertLineToCurrencyObject(Line));
			}

			MyFile.close();
		}
		return vCurrency;
	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency C : vCurrencys)
			{
				DataLine = _ConvertCurrencyObjectToLine(C);
				MyFile << DataLine << endl;
			}

			MyFile.close();
		}

	}

	void _Update()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencysDataFromFile();

		for (clsCurrency& C : _vCurrencys)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}

		}

		_SaveCurrencyDataToFile(_vCurrencys);

	}

	
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(_enMode::EmptyMode, "", "", "", 0);
	}

public: 

	clsCurrency(_enMode Mode , string Country , string CurrencyCode ,string CurrencyName ,float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == _enMode::EmptyMode);
	}

	 string Country()
	{
		return _Country;
	}

	 string CurrencyCode()
	 {
		 return _CurrencyCode;
	 }

	 string CurrencyName()
	 {
		 return _CurrencyName;
	 }

	 float Rate()
	 {
		 return _Rate;
	 }

	  void UpdateRate(float Rate)
	 {
		 _Rate = Rate;
		 _Update();
	 }

	 static clsCurrency FindByCurrencyCode(string CurrencyCode)
	 {
		 CurrencyCode = clsString::UpperAllLetterOfWord(CurrencyCode);

		 fstream MyFile;
		 MyFile.open("Currencies.txt", ios::in);//Read only

		 if (MyFile.is_open())
		 {
			 string Line;
			 
			 while (getline(MyFile, Line))
			 {
				 clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				 if (Currency.CurrencyCode() == CurrencyCode)
				 {
					 MyFile.close();
					 return Currency;
				 }
			 }
			 MyFile.close();
		 }
	 }

	 static clsCurrency FindByCurrencyName(string CurrencyName)
	 {
		 CurrencyName = clsString::UpperAllLetterOfWord(CurrencyName);

		 fstream MyFile;
		 MyFile.open("Currencies.txt", ios::in);//Read only

		 if (MyFile.is_open())
		 {
			 string Line;

			 while (getline(MyFile, Line))
			 {
				 clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				 if (clsString::UpperAllLetterOfWord(Currency.CurrencyName()) == CurrencyName)
				 {
					 MyFile.close();
					 return Currency;
				 }
			 }
			 MyFile.close();
		 }
	 }

	 static bool IsCurrencyExist(string CurrencyCode)
	 {
		 clsCurrency Currency = FindByCurrencyCode(CurrencyCode);
		 return (!Currency.IsEmpty());
   	 }

	 static vector <clsCurrency> GetCurrenciesList()
	 {
		 return _LoadCurrencysDataFromFile();
	 }

	 float ConvertToUSD(float Amount)
	 {
		 return (float)(Amount / Rate());
	 }

	 float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	 {
		 float AmountInUSD = ConvertToUSD(Amount);

		 if (Currency2.CurrencyCode() == "USD")
		 {
			 return AmountInUSD;
		 }

		 return (float)(AmountInUSD * Currency2.Rate());

	 }
};

