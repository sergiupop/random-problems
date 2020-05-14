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

struct pointComparator {
    bool operator() (const point& point1, const point& point2) const
    {
        return point1.x < point2.x&& point1.y < point2.y;
    }
};

int main()
{
    int N, x, y, R;
    cin >> N >> x >> y >> R;

    std::set<point, pointComparator> points;

    for (int i = 0; i < N; i++) {
        point myPoint;
        cin >> myPoint.x >> myPoint.y;
        points.insert(myPoint);
    }

    int pointsInside = 0;
    for (auto const& bi : points) {
        int xDistance = abs(bi.x - x);
        int yDistance = abs(bi.y - y);
        double inCircleDistance = sqrt(xDistance * xDistance + yDistance * yDistance);

        if (inCircleDistance <= R) pointsInside++;
    }

    cout << pointsInside;

    return 0;
}