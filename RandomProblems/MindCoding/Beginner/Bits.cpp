/*** https://mindcoding.ro/pb/bits ***/

#include <iostream>
#include <math.h>

using namespace std;
int main()
{
    int N;
    cin >> N;

    int* numbers = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < N; i++) {
        int currentNumber = numbers[i];
        int numberBits[32] = { };

        int currentBitPosition = 0;
        while (currentNumber > 0) {
            numberBits[currentBitPosition] = currentNumber % 2;
            currentNumber /= 2;
            currentBitPosition++;
        }

        int zeroIndexToSwap = -1;
        int oneIndexToSwap = -1;
        for (int j = currentBitPosition - 1; j >= 0; j--) {
            if (numberBits[j] == 0 && zeroIndexToSwap == -1) {
                zeroIndexToSwap = j;
            }

            if (numberBits[j] == 1 && zeroIndexToSwap != -1) {
                oneIndexToSwap = j;
            }
        }

        if (oneIndexToSwap != -1) {
            numberBits[zeroIndexToSwap] = 1;
            numberBits[oneIndexToSwap] = 0;
        }

        int maxNumber = 0;
        for (int j = 0; j < currentBitPosition; j++) {
            maxNumber += numberBits[j] * pow(2, j);
        }

        cout << maxNumber << " ";
    }

    return 0;
}