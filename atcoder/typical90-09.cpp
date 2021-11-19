#include <bits/stdc++.h>

using namespace std;

struct Point
{
    double x, y;
};

Point operator-(const Point &lhs, const Point &rhs)
{
    return Point{lhs.x - rhs.x, lhs.y - rhs.y};
}

double calc_argument(Point p)
{
    double cos = p.x / sqrt(p.x * p.x + p.y * p.y);
    double theta = acos(cos) * 180.0 / M_PI;
    if (0.0 <= p.y)
        return theta;
    return 360.0 - theta;
}

// b番目の点をBとしたときの∠ABC
double calc_argument_with_middle(int b, int N, vector<Point> Ps)
{
    vector<double> angles;
    for (int i = 1; i <= N; i++)
    {
        if (b == i)
            continue;
        double angle = calc_argument(Ps[i] - Ps[b]); // 点Bを原点としたときの各点の座標から偏角を計算
        angles.push_back(angle);
    }
    sort(angles.begin(), angles.end());

    double ret = 0.0;

    // 点Aについて全探索
    for (int a = 0; a < angles.size(); a++)
    {
        double maximum = angles[a] + 180.0; // 点Aの真向かいの位置の偏角
        if (360.0 <= maximum)
            maximum -= 360.0;
        int pos = lower_bound(angles.begin(), angles.end(), maximum) - angles.begin(); // 点Aの真向かいの位置に最も近い点を探す

        int c0 = pos % angles.size();
        double c0arg = angles[a] - angles[c0];
        if (180.0 <= c0arg)
            c0arg = 360.0 - c0arg;

        int c1 = (pos + angles.size() - 1) % angles.size();
        double c1arg = angles[a] - angles[c1];
        if (180.0 <= c1arg)
            c1arg = 360.0 - c1arg;
        ret = max(ret, max(c0arg, c1arg));
    }
    return ret;
}

int main()
{
    int N;
    cin >> N;
    vector<Point> Ps(N + 1);
    for (int i = 1; i <= N; i++)
    {
        double x, y;
        cin >> x >> y;
        Ps[i] = Point{x, y};
    }

    double ans = 0.0;

    // Bについて全探索
    for (int b = 1; b <= N; b++)
    {
        double argument = calc_argument_with_middle(b, N, Ps);
        ans = max(ans, argument);
    }

    cout << setprecision(12) << ans << endl;
    return 0;
}