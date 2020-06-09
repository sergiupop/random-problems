/*** https://mindcoding.ro/pb/lumber_dashes ***/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string myString;
	string myStringCorrected;

	getline(cin, myString);

	for (char const& c : myString) {
		if (c == '-' || c == '.') continue;
		if (c == ',') {
			myStringCorrected += ' ';
		}

		myStringCorrected += c;
	}

	cout << myStringCorrected;

	return 0;
}