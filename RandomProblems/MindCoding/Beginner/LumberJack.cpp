/*** https://mindcoding.ro/pb/lumber_number ***/

#include <iostream>
#include <string> 

using namespace std;
int main()
{
	int x;
	cin >> x;

	string xAsString = to_string(x);
	string xWithDashes;

	for (char const& c : xAsString) {
		xWithDashes += c;
		xWithDashes += '-';
	}

	cout << xWithDashes.substr(0, xWithDashes.size() - 1);

	return 0;
}