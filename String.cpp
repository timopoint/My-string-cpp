#include "String.h"
#include <iostream>

namespace Mystd
{

	unsigned int String::len(const char* str) const
	{
		int ind = 0;
		while (str[ind] != '\0')
		{
			ind++;
		}
		ind++;
		return ind;
	}

	void String::revers()
	{
		for (unsigned int i = 0; i < (strsize - 1)/2; i++)
		{
			char tmp;
			tmp = string[i];
			string[i] = string[strsize - i - 2];
			string[strsize - i - 2] = tmp;
		}
	}

	void String::revers(String& str)
	{
		for (unsigned int i = 0; i < (str.strsize - 1) / 2; i++)
		{
			char tmp;
			tmp = str.string[i];
			str.string[i] = str.string[str.strsize - i - 2];
			str.string[str.strsize - i - 2] = tmp;
		}
	}

	String& String::operator=(const char* str)
	{
		delete[] string;
		strsize = len(str);
		string = new char[strsize];

		for (unsigned int i = 0; i < strsize; i++)
		{
			string[i] = str[i];
		}

		return *this;
	}

	String& String::operator= (const String& str)
	{

		delete[] string;
		strsize = str.strsize;
		string = new char[strsize];

		for (unsigned int i = 0; i < strsize; i++)
		{
			string[i] = str.string[i];
		}

		return *this;
	}

	String String::operator+ (const char* str)
	{
		String newstr;

		newstr.strsize = strsize + len(str) - 1;

		delete[] newstr.string;
		newstr.string = new char[newstr.strsize];

		for (unsigned int i = 0; i < strsize - 1; i++)
		{
			newstr.string[i] = string[i];
		}

		for (unsigned int i = strsize - 1; i < newstr.strsize; i++)
		{
			newstr.string[i] = str[i - strsize + 1];
		}

		return newstr;
	}

	String String::operator+ (const String& str)
	{
		String newstr;

		newstr.strsize = strsize + str.strsize - 1;

		delete[] newstr.string;
		newstr.string = new char[newstr.strsize];

		for (unsigned int i = 0; i < strsize - 1; i++)
		{
			newstr.string[i] = string[i];
		}

		for (unsigned int i = strsize - 1; i < newstr.strsize; i++)
		{
			newstr.string[i] = str.string[i - strsize + 1];
		}

		return newstr;
	}

	String& String::operator+=(const String& str)
	{
		*this = *this + str;
		return *this;

	}

	String& String::operator+=(const char* str)
	{
		*this = *this + str;
		return *this;

	}

	String String::operator- () const
	{
		String newstr = *this;
		newstr.revers();
		return newstr;
	}

	String& String::operator*(const int amount)
	{
		String newstr;
		
		if (amount < 1)
		{
			return newstr;
		}

		delete[] newstr.string;
		newstr.strsize = strsize * amount;

		for (int i = 0; i < amount; i++)
		{
			for (unsigned int j = strsize * i; j < strsize + strsize * i; i++)
			{
				newstr.string[j] = string[j - strsize * i];
			}
		}

		return newstr;
	}

	bool String::operator==(const String& str)
	{
		for (unsigned int i = 0; i < strsize; i++)
		{
			if (string[i] != str.string[i]) return 0;
		}
		return 1;
	}

	bool String::operator!=(const String& str)
	{
		for (unsigned int i = 0; i < strsize; i++)
		{
			if (string[i] == str.string[i]) return 0;
		}
		return 1;
	}

	char String::operator[](const unsigned int ind)
	{
		if (ind < 0 || ind >= strsize)
			throw std::invalid_argument("Recieved out of bounds value");
		return string[ind];
	}

	int String::operator()(const char ch)
	{
		for (unsigned int i = 0; i < strsize; i++)
		{
			if (string[i] == ch) return i;
		}
		return -1;
	}

	std::ostream& operator<<(std::ostream& o, const String& str)	
	{
		o << str.string;
		return o;
	}

	std::istream& operator>>(std::istream i, String& str)
	{
		i.getline(str.string, String::getstatic);
		return i;
	}

	
}