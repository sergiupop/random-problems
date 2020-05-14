/*** https://mindcoding.ro/pb/bitcount ***/

#include <iostream>

using namespace std;
int main()
{
	int n;
	cin >> n;
	int bitsOf1Count = 0;

	while (n > 0) {
		if (n % 2 == 1)
			bitsOf1Count++;
		n /= 2;
	}

	cout << bitsOf1Count;

	return 0;
}