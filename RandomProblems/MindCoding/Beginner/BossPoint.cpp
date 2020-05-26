/*** https://mindcoding.ro/pb/bosspoint ***/

#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct point {
    int x;
    int y;
    double distanceToBoss;
};

bool compareTwoPoints(point a, point b)
{
    if (a.distanceToBoss != b.distanceToBoss)
        return a.distanceToBoss < b.distanceToBoss;

    return (a.x != b.x) ? (a.x < b.x) : (a.y < b.y);
}

int main()
{
    int N, K, xBoss, yBoss;
    cin >> N >> K >> xBoss >> yBoss;

    struct point* points = new point[N];
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    for (int i = 0; i < N; i++) {
        int xDistance = abs(points[i].x - xBoss);
        int yDistance = abs(points[i].y - yBoss);
        points[i].distanceToBoss = sqrt(xDistance * xDistance + yDistance * yDistance);
    }

    sort(points, points + N, compareTwoPoints);

    for (int i = 0; i < K; i++) {
        cout << points[i].x << ' ' << points[i].y << endl;
    }

    delete[] points;

    return 0;
}