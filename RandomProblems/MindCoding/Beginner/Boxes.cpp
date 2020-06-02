/*** https://mindcoding.ro/pb/boxes ***/

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

struct box {
    int whiteMarbles;
    int blackMarbles;
};

bool compareBoxesByBlackMarbles(box box1, box box2) {
    return box1.blackMarbles >= box2.blackMarbles;
}

bool compareBoxesByWhiteMarbles(box box1, box box2) {
    return box1.whiteMarbles >= box2.whiteMarbles;
}

int main()
{
    int N, M;
    cin >> N >> M;

    struct box* boxes = new box[N];
    for (int i = 0; i < N; i++) {
        cin >> boxes[i].whiteMarbles >> boxes[i].blackMarbles;
    }

    sort(boxes, boxes + N, compareBoxesByBlackMarbles);
    int blackMarbles = 0;
    for (int i = 0; i < N/2; i++) {
        blackMarbles += boxes[i].blackMarbles;
    }

    sort(boxes, boxes + N, compareBoxesByWhiteMarbles);
    int whiteMarbles = 0;
    for (int i = 0; i < N/2; i++) {
        whiteMarbles += boxes[i].whiteMarbles;
    }

    cout << blackMarbles << " " << whiteMarbles;

    return 0;
}