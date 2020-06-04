/*** https://mindcoding.ro/pb/domimatrix ***/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int* numbers = new int[N * N];
	for (int i = 0; i < N * N; i++) {
		cin >> numbers[i];
	}

	sort(numbers, numbers + N * N, greater<int>());

	int index = N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << (i == j ? numbers[i] : numbers[index++]) << " ";
		}

		cout << endl;
	}

	return 0;
}