/*** https://mindcoding.ro/pb/gray ***/

#include <iostream>
#include <math.h>

using namespace std;
int main()
{
    int N;
    cin >> N;
    if (N < 1 || N > 12) return 0;

    int configsCount = (int)pow(2, N);
    int** configs = new int* [configsCount];
    for (int i = 0; i < configsCount; i++) {
        configs[i] = new int[N];
        for (int j = 0; j < N; j++) {
            configs[i][j] = 0;
        }
    }

    configs[0][N - 1] = 0;
    configs[1][N - 1] = 1;

    for (int k = 2; k <= N; k++) {
        int currentStep = (int)pow(2, k);

        for (int i = 0; i < currentStep / 2; i++) {
            for (int j = N - 1; j >= N - k + 1; j--) {
                configs[currentStep - 1 - i][j] = configs[i][j];
            }
            configs[i][N - k] = 0;
        }
        for (int i = currentStep / 2; i < currentStep; i++) {
            configs[i][N - k] = 1;
        }
    }

    for (int i = 0; i < configsCount; i++) {
        for (int j = 0; j < N; j++) {
            cout << configs[i][j];
        }
        cout << endl;
    }

    return 0;
}