#include <iostream>
#include "String.h"

int main()
{
	using string = Mystd::String;
	using std::cout;
	using std::cin;

	string str1;

	{

		try
		{
			str1[7];
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
		}

		string str2;

		str1 = "some text here now!\n";
		str2 = "and new some text there)\n";
		string str3 = str1 + str2 + "hehe, some text in this place)))\n";


		cout << str1 << std::endl;
		cout << str3 << std::endl;

		cout << std::endl;
		str3 += "132541234213";
		cout << str3 << std::endl;
		cout << std::endl;
		str3 = "";
		cout << std::endl;
		str3 += str1;
		cout << str3 << std::endl;
		cout << std::endl;
		str1 += str1;
		cout << str1 << std::endl;
		cout << std::endl;
		str3 += str1;
		cout << str3 << std::endl;
		cout << std::endl;
		cout << str2 + str3;
		cout << std::endl;
		cout << "ind: " << str1('h') << ";\n";
		cout << std::endl;
	}

	str1 = "omomom"; // 6 symb without '\0'
	cout << (int)str1 << std::endl; 
	cout << std::endl;
	str1 = "132541234213";
	cout << str1 << std::endl;
	str1.revers();
	cout << str1 << std::endl;
	string::revers(str1);
	cout << str1 << std::endl;
	
	str1.revers();
	cout << str1 << std::endl;
	cout << -str1;

}