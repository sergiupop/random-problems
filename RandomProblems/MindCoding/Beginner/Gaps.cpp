/*** https://mindcoding.ro/pb/gaps ***/

#include <iostream>

using namespace std;
int main()
{
    int N;
    cin >> N;

    if (N < 1 || N > 100) return 0;

    int* numbers = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    int currentIntervalLimit = 1, currentNumbersIndex = 0;
    bool isGapStarted = false, areThereAnyGaps = false;

    for (int i = 1; i <= 100; i++) {
        if (i == numbers[currentNumbersIndex]) {
            if (isGapStarted) {
                areThereAnyGaps = true;
                cout << currentIntervalLimit << "-" << i-1 << endl;
            }

            currentNumbersIndex++;
            isGapStarted = false;
            continue;
        }

        if (!isGapStarted) {
            isGapStarted = true;
            currentIntervalLimit = i;
        }
    }

    if (isGapStarted) {
        areThereAnyGaps = true;
        cout << currentIntervalLimit << "-" << 100 << endl;
    }

    if (!areThereAnyGaps) {
        cout << "All clear!";
    }

    return 0;
}