/*** https://mindcoding.ro/pb/ten ***/

#include <iostream>
#include <string> 

using namespace std;

int getAlphabetValueForChar(char c) {
	return c - 'a' + 1;
}

int main()
{
	string myString;
	cin >> myString;

	int maxSum = 0;
	int currentSum = 0;
	for (int i = 0; i < myString.size(); i++) {
		int currentCharValue = getAlphabetValueForChar(myString[i]);
		if (i < 10) {
			currentSum += currentCharValue;
		}
		else {
			currentSum = currentSum - getAlphabetValueForChar(myString[i - 10]) + currentCharValue;
		}

		if (currentSum > maxSum) {
			maxSum = currentSum;
		}
	}

	cout << maxSum;

	return 0;
}