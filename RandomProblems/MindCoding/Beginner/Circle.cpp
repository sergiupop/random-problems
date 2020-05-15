/*** https://mindcoding.ro/pb/circle ***/

#include <iostream>
#include <set>
#include <math.h>
#include <stdlib.h>

using namespace std;

struct point {
    int x;
    int y;
};

int main()
{
    int N, x, y, R;
    cin >> N >> x >> y >> R;

    struct point* points = new point[N];
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    int pointsInside = 0;
    for (int i = 0; i < N; i++) {
        int xDistance = abs(points[i].x - x);
        int yDistance = abs(points[i].y - y);
        double inCircleDistance = sqrt(xDistance * xDistance + yDistance * yDistance);

        if (inCircleDistance <= R) pointsInside++;
    }

    delete[] points;

    cout << pointsInside;

    return 0;
}