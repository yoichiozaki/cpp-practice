#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
};

int main()
{
    vector<Point> ps;
    double x, y;
    char comma;
    while (cin >> x >> comma >> y)
    {
        ps.push_back(Point(x, y));
    }
    double ans = 0.0;
    for (int i = 1; i <= ps.size() - 2; i++)
    {
        Point p0 = ps[0];
        Point p1 = ps[i];
        Point p2 = ps[i + 1];
        double a = sqrt((p0.x - p1.x) * (p0.x - p1.x) + (p0.y - p1.y) * (p0.y - p1.y));
        double b = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
        double c = sqrt((p2.x - p0.x) * (p2.x - p0.x) + (p2.y - p0.y) * (p2.y - p0.y));
        double z = (a + b + c) / 2;
        ans += sqrt(z * (z - a) * (z - b) * (z - c));
    }
    cout << fixed << setprecision(12) << endl;
    cout << ans << endl;
    return 0;
}