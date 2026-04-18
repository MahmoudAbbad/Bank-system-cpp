#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString
{
private:
	string _Value;

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short CountWords(string S1)
	{

		string delim = " "; // delimiter  
		short Counter = 0;
		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			if (sWord != "")
			{
				Counter++;
			}

			//erase() until positon and move to next word.
			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			Counter++; // it counts the last word of the string.
		}

		return Counter;

	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	static string UpperAllLetterOfWord(string Str)
	{
		for (int i = 0; i < Str.length(); i++)
		{
			Str[i] = toupper(Str[i]);

		}

		return Str;
	}

	string UpperAllLetterOfWord()
	{
		return _Value = UpperAllLetterOfWord(_Value);
	}

	static string LowerAllLetterOfWord(string Str)
	{
		for (int i = 0; i < Str.length(); i++)
		{
			Str[i] = tolower(Str[i]);

		}
		return Str;
	}


	string LowerAllLetterOfWord()
	{
		return _Value = LowerAllLetterOfWord(_Value);
	}

	static char InvertChar(char C)
	{
		return (isupper(C) ? tolower(C) : toupper(C));
	}

	static bool IsVowel(char Letter)
	{
		Letter = tolower(Letter);

		return ((Letter == 'a') || (Letter == 'e') || (Letter == 'o') || (Letter == 'i') || (Letter == 'u'));
	}

	static vector <string> SplitString(string Str, string delim)
	{
		vector <string> vString;
		short pos = 0;
		string sword;

		while ((pos = Str.find(delim)) != string::npos)
		{
			sword = Str.substr(0, pos);
			if (sword != "")
			{
				vString.push_back(sword);
			}

			Str.erase(0, pos + delim.length());

		}

		if (Str != "")
		{
			vString.push_back(Str);
		}

		return vString;

	}

	static string TrimLeft(string Str)
	{
		for (int i = 0; i < Str.length(); i++)
		{
			if (Str[i] != ' ')
			{
				return Str.substr(i, Str.length());
			}
		}
	}

	string TrimLeft()
	{
		return _Value = TrimLeft(_Value);
	}

	static string TrimRight(string Str)
	{
		for (int i = Str.length() - 1; i >= 0; i--)
		{
			if (Str[i] != ' ')
			{
				return Str.substr(0, i + 1);
			}

		}

	}

	string TrimRight()
	{
		return _Value = TrimRight(_Value);
	}

	static string Trim(string Str)
	{
		return TrimLeft(TrimRight(Str));
	}

	string Trim()
	{
		return _Value = Trim(_Value);
	}

	static string ReverseWord(string S1)
	{
		vector <string> vString;
		string S2;

		vString = SplitString(S1, " ");

		vector <string>::iterator iter = vString.end();


		while (iter != vString.begin())
		{
			iter--;
			S2 += *iter + " ";

		}

		S2 = S2.substr(0, S2.length() - 1);
		return S2;
	}

	string ReverseWord()
	{
		return _Value = ReverseWord(_Value);
	}

	static string ReplaceWord(string Str, string OldWord, string UpdateWord)
	{
		short pos = Str.find(OldWord);

		while (pos != string::npos)
		{
			Str.replace(pos, OldWord.length(), UpdateWord);
			pos = Str.find(OldWord);
		}
		return Str;
	}

	string ReplaceWord(string OldWord, string UpdateWord)
	{
		return _Value = ReplaceWord(_Value, OldWord, UpdateWord);
	}

	static string RemovePuncuations(string Str)
	{
		string S2 = "";

		for (int i = 0; i < Str.length(); i++)
		{
			if (!ispunct(Str[i]))
				S2 += Str[i];
		}
		return S2;
	}

	string RemovePuncuations()
	{
		return _Value = RemovePuncuations(_Value);
	}

};

