/*** https://mindcoding.ro/pb/gray ***/

#include <iostream>
#include <math.h>
#include <map>

using namespace std;

int N;
map<int, int*> numbersConfigs;
int* occurences;

int* computeNumberConfig(int nr) {
    int* currentConfig = new int[N];
    for (int i = 0; i < N; i++) {
        currentConfig[i] = 0;
    }

    int counter = N - 1;
    while (nr > 0) {
        currentConfig[counter] = nr % 2;;
        nr /= 2;
        counter--;
    }

    return currentConfig;
}

bool isSafe(int** configs, int nr, int pos) {
    if (pos == 0) return true;
    if (occurences[nr] == 1) return false;

    int* currentConfig = numbersConfigs.find(nr)->second;
    int differencesCounter = 0;
    for (int i = 0; i < N; i++) {
        if (configs[pos - 1][i] != currentConfig[i]) differencesCounter++;
        if (differencesCounter > 1) return false;
    }

    return differencesCounter == 0 ? false : true;
}

bool solve(int** configs, int configsCount, int pos) {
    if (pos >= configsCount) return true;

    for (int i = 0; i < configsCount; i++) {
        if (isSafe(configs, i, pos)) {
            occurences[i] = 1;
            int* computedConfig = numbersConfigs.find(i)->second;
            for (int j = 0; j < N; j++) {
                configs[pos][j] = computedConfig[j];
            }

            if (solve(configs, configsCount, pos + 1)) return true;

            occurences[i] = 0;
            for (int j = 0; j < N; j++) {
                configs[pos][j] = 0;
            }
        }
    }

    return false;
}

int main()
{
    cin >> N;
    if (N < 1 || N > 12) return 0;

    int configsCount = (int)pow(2, N);
    int** configs = new int* [configsCount];
    occurences = new int[configsCount];

    for (int i = 0; i < configsCount; i++) {
        int* currentConfig = computeNumberConfig(i);
        occurences[i] = 0;
        numbersConfigs[i] = new int[N];
        configs[i] = new int[N];
        for (int j = 0; j < N; j++) {
            configs[i][j] = 0;
            numbersConfigs[i][j] = currentConfig[j];
        }
    }

    if (solve(configs, configsCount, 0) == true) {
        for (int i = 0; i < configsCount; i++) {
            for (int j = 0; j < N; j++) {
                cout << configs[i][j];
            }
            cout << endl;
        }
    }
    else {
        cout << "No solution exists!";
    }

    return 0;
}