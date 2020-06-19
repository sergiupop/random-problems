/*** https://mindcoding.ro/pb/maxrev ***/

#include <iostream>

using namespace std;

int main()
{
	int N, currentNr;
	long long int reversedNumbers[100];

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> currentNr;
		reversedNumbers[i] = 0;
		while (currentNr > 0) {
			reversedNumbers[i] = reversedNumbers[i] * 10 + currentNr % 10;
			currentNr /= 10;
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		cout << reversedNumbers[i] << endl;
	}

	return 0;
}