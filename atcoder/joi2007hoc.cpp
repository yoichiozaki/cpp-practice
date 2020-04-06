#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    set<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        points.insert(pair<int, int>(x, y));
    }
    long long sum, ans = 0;
    for (auto c: points) {
        for (auto v: points) {
            if (c == v) continue;
            int dx = v.first - c.first;
            int dy = v.second - c.second;
            int nx1 = v.first - dy;
            int ny1 = v.second + dx;
            int nx2 = c.first - dy;
            int ny2 = c.second + dx;

            if (points.count(pair<int, int>(nx1, ny1)) && points.count(pair<int, int>(nx2, ny2))) {
                sum = dy * dy + dx * dx;
                ans = max(ans ,sum);
            }
        }
    }
    cout << ans << endl;
    return 0;
}