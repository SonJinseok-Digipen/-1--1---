
#include <iostream>
#include <string>

using namespace std;

// You may NOT use any library functions like pow, reverse, or other things
// You may NOT use to_string or any other library functions like that
// I am providing you this infomormation for a reason, this is how I want you to implement it as shown here
// If this does not make sense, ask the teacher, a TA or another student who does understand! 
//
// Adding a value to the string can be as easy as value + string (str = '0' + str or str = '1' + str)
// This will add the letter 0 or a 1 to the front of the string
// If binString = "1011" then binString = '1' + binString. now binString = "11011" 
string ConvertDecToBin(int decimal)
{
	string binString = "";
	while (decimal>=1)
	{
	
		if (decimal % 2 == 1)
		{
			binString='1'+binString;
		}
		if (decimal % 2 == 0)
		{
			binString = '0' + binString;
		}
		decimal /= 2;
				
	}
	return binString;
}

// You may NOT use any library functions like pow, reverse, or other things
// You may NOT use to_string or any other library functions like that
// I am providing you this infomormation for a reason, this is how I want you to implement it as shown here
// If this does not make sense, ask the teacher, a TA or another student who does understand! 
//
// you can use binString[index] to get the character at the location index 
// if binString = "1011", binString[0] = '1', binString[1] = '0', binString[2] = '1', binString[3] = 1
// binString.length() - 1 will give you the last letter in the string. If binString = "1011", binString.length() - 1 = 3
int ConvertBinToDec(string binString)
{
	int decimal = 0;
	int index = binString.length() - 1;
	int power2 = 1;
	// YOUR CODE HERE
	for (int i = index; i >= 0; i--)
	{
		if (binString[i] == '0')
		{
			decimal += 0 * power2;
		}

		if (binString[i] == '1')
		{
			decimal += 1 * power2;
		}

		power2 = power2 * 2;
	}
	return decimal;
}

bool VerifyBinString(string binString) {
	for (char c : binString) {
		if (c != '0' && c != '1') {
			return false;
		}
	}
	return true;
}

int main() {
	int algo = 0;

	cout << "Enter Algorithm to run" << endl;
	cout << "1 to Convert Decimal to Binary String" << endl;
	cout << "2 to Convert Binary String to Decimal" << endl;

	cin >> algo;
#ifndef _MSC_VER
	cout << std::endl;
#endif

	switch (algo) {
	case 1:
		int decimal;
		cout << "Enter the decimal value to convert: ";
		cin >> decimal;
#ifndef _MSC_VER
		cout << std::endl;
#endif
		if (cin.fail() == false) {
			cout << decimal << " in binary = 0b" << ConvertDecToBin(decimal) << endl;
		}
		break;
	case 2:
		string binString;
		cout << "Enter the binary string to convert: 0b";
		cin >> binString;
#ifndef _MSC_VER
		cout << std::endl;
#endif
		if (VerifyBinString(binString) == true) {
			cout << "0b" << binString << " in decimal = " << ConvertBinToDec(binString) << endl;
		}
		else {
			cout << "Error in the binary string" << endl;
		}
		break;
	}
}