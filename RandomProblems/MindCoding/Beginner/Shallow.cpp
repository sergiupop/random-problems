/*** https://mindcoding.ro/pb/shallow ***/

#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
    int N, M, hMin, hMax;
    cin >> N >> M >> hMin >> hMax;

    int* girlfriends = new int[N];
    int* shoes = new int[M];
    for (int i = 0; i < N; i++) {
        cin >> girlfriends[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> shoes[i];
    }

    sort(girlfriends, girlfriends + N);
    sort(shoes, shoes + M, greater<int>());

    bool allGirlfriendsAreOkSoFar = true;
    int badGirlfriendsLimitIndex = -1;

    for (int i = N-1; i >= 0 ; i--) {
        if (girlfriends[i] > hMax) {
            allGirlfriendsAreOkSoFar = false;
            break;
        }
        
        if (girlfriends[i] < hMin) {
            badGirlfriendsLimitIndex = i;
            break;
        }
    }

    if (allGirlfriendsAreOkSoFar) {
        for (int i = 0; i <= badGirlfriendsLimitIndex; i++) {
            bool girlfriendIsOk = false;

            for (int j = 0; j < M; j++) {
                if (shoes[j] == -1) continue;
                int girlfriendNewHeight = girlfriends[i] + shoes[j];

                if ((hMin <= girlfriendNewHeight) && (girlfriendNewHeight <= hMax)) {
                    shoes[j] = -1;
                    girlfriendIsOk = true;
                    break;
                }
            }

            if (!girlfriendIsOk) {
                allGirlfriendsAreOkSoFar = false;
                break;
            }
        }
    }

    cout << (allGirlfriendsAreOkSoFar ? "Yes" : "No");

    delete[] girlfriends;
    delete[] shoes;

    return 0;
}