/*** https://mindcoding.ro/pb/gb ***/

#include <iostream>

using namespace std;
int main()
{
	int n, x;
	cin >> n >> x;

	int currentCode;
	while (n > 0) {
		cin >> currentCode;
		if (currentCode != x) cout << currentCode << " ";
		n--;
	}

	return 0;
}