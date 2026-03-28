#pragma once
#ifndef STRING_H
#define STRING_H

#include <iostream>

namespace Mystd
{


	class String
	{
		unsigned int strsize;
		char* string;

	protected:
		inline static int strcount = 0;
		static const int getstatic = 4048;

	public:

		unsigned int len(const char*) const;

		void revers();
		static void revers(String& str);

		String(const char* str = "") :
			strsize{ len(str) },
			string{ new char[strsize] {(char)str} }
		{
			strcount++;
		}

		String(const String& str) {

			strsize = str.strsize;
			string = new char[strsize];
			for (int i = 0; i < strsize; i++)
			{
				string[i] = str.string[i];
			}   
		}

		String(String&& other) noexcept
		{
			string = other.string;
			strsize = other.strsize;

			other.string = nullptr;
			other.strsize = 0;
		}

		~String()
		{
			delete[] string;
			strcount--;
		}

		int getCountStr() { return strcount; }

		//String() : String("") {}

		String& operator=(const char* str);
		String& operator=(const String& str);

		String operator+(const String& str);
		String operator+(const char* str);

		String& operator+=(const String& str);
		String& operator+=(const char* str);

		String operator- () const;

		String operator*(const int);

		bool operator==(const String& str);
		bool operator!=(const String& str);

		char operator[](const unsigned int);

		operator int() const
		{
			return strsize - 1;
		}
		

		int operator()(const char);

		friend std::ostream& operator<< (std::ostream& o, const String& str);
		friend std::istream& operator>> (std::istream o, String& str);


	};


}


#endif