#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x, y;
};

int main()
{

    Point point[1001];
    point[2].x = 1.0;
    point[2].y = 1.0;

    double degree, pre_slope, next_slope;

    pre_slope = sqrt(2);

    for (int i = 3; i <= 1000; i++)
    {
        next_slope = sqrt(pre_slope * pre_slope + 1);
        degree = acos((pre_slope * pre_slope + next_slope * next_slope - 1) / (2 * pre_slope * next_slope));
        point[i].x = (cos(-1 * degree) * point[i - 1].x - sin(-1 * degree) * point[i - 1].y) * (next_slope / pre_slope);
        point[i].y = (sin(-1 * degree) * point[i - 1].x + cos(-1 * degree) * point[i - 1].y) * (next_slope / pre_slope);
        pre_slope = next_slope; //
    }

    int n;

    while (true)
    {
        scanf("%d", &n);
        if (n == -1)
            break;

        printf("%.2lf\n%.2lf\n", point[n].y, point[n].x);
    }

    return 0;
}