/*** https://mindcoding.ro/pb/pharmacy ***/

#include <iostream>

using namespace std;
int main()
{
	int M, currentArraySize = 0, operationType, operationValue;
	cin >> M;

	int* myArray = new int[M];
	for (int i = 0; i < M; i++) {
		myArray[i] = 0;
	}

	while(M--) {
		cin >> operationType;

		switch (operationType) {
			case 1: {
				cin >> operationValue;
				myArray[currentArraySize] = operationValue;
				currentArraySize++;
				break;
			}

			case 2: {
				if (currentArraySize == 0) break;

				currentArraySize--;
				myArray[currentArraySize] = 0;
				break;
			}

			case 3: {
				cin >> operationValue;
				bool anyElement = false;
				for (int j = 0; j < currentArraySize; j++) {
					if (myArray[j] <= operationValue) {
						cout << myArray[j] << ' ';
						anyElement = true;
					}
				}

				if (anyElement) {
					cout << endl;
				}
				else {
					cout << "Empty" << endl;
				}
				break;
			}

			default: break;
		}
	}

	return 0;
}