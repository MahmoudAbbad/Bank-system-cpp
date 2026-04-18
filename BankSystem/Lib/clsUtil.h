#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;

class clsUtil
{

public: 

	enum enCharType { Number = 1, CapitalLatter = 2, SmallLatter = 3, SpitialCharacter = 4 , MixChar = 5};

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(short From, short To)
	{
		return rand() % (To - From + 1) + From;
	}

	static char GetRandomCharacter(enCharType Random)
	{
		enCharType Rand;

		if (Random == enCharType::MixChar)
			Rand = (enCharType)RandomNumber(1, 3);
		else
			Rand = Random;

		switch (Rand)
		{
		case enCharType::Number:
			return char(RandomNumber(48, 57));
			break;
		case enCharType::CapitalLatter:
			return char(RandomNumber(65, 90)) ;
			break;
		case enCharType::SmallLatter:
			return char(RandomNumber(97, 122));
			break;
		case enCharType::SpitialCharacter:
			return char(RandomNumber(33, 47));
			break;
		}
	}

	static string GenerateWord(enCharType CharType, short lenght)
	{
		string Word = "";

		for (int i = 1; i <= lenght; i++)
		{
			Word += char(GetRandomCharacter(CharType));
		}
		return Word;
	}

	static string GenerateKey(enCharType CharType)
	{
		string Key = "";

		for (int i = 1; i <= 4; i++)
		{
			Key += GenerateWord(CharType, 4);
			if (i < 4)
				Key += '-';
		}

		return Key;
	}

	static void GenerateKeys(short NumberOfKeys , enCharType CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "]: " << GenerateKey(CharType) << endl;
		}
	}

	static void Swap(int& a, int& b)
	{
		int Temp = a;
		a = b;
		b = Temp;
	}

	static  void Swap(double& A, double& B)
	{
		double Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(string& a, string& b)
	{
		string Temp = a;
		a = b;
		b = Temp;
	}

	static  void Swap(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate::SwapDates(Date1, Date2);
	}

	static  void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}

	}

	static void FillArrayWithRandomNumber(int arr[100], int arlenght, short From, short To)
	{
		for (int i = 0; i < arlenght; i++)
		{
			//cout << "Element [" << i+1 << "] : ";
			arr[i] = RandomNumber(From, To);

		}
	}

	static void FillArrayWithRandomWords(string arr[100], int arlenght, enCharType CharType, short Lenght)
	{
		for (int i = 0; i < arlenght; i++)
		{
			//cout << "Element [" << i+1 << "] : ";
			arr[i] = GenerateWord(CharType , Lenght);

		}
	}

	static void FillArrayWithRandomKeys(string arr[100], int arlenght, enCharType CharType)
	{
		for (int i = 0; i < arlenght; i++)
		{
			//cout << "Element [" << i+1 << "] : ";
			arr[i] = GenerateKey(CharType);

		}
	}

	static string Tabs(short NumberOfTaps)
	{
		string T = "";

		for (short i = 1; i <= NumberOfTaps; i++)
		{
			T += "\t";
		}

		return T;
	}

	static string EncryptText(string Text, short EncryptKey=5)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptKey);
		}

		return Text;
	}

	static string DecryptText(string Text, short EncryptKey=5)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptKey);
		}

		return Text;
	}

	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}
	}
};

