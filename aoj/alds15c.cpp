#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
};

void koch(int d, point a, point b) {
    if (d == 0) return;

    point s, t, u;
    double th = M_PI * 60.0 / 180.0;

    s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
    s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
    t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
    t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    koch(d-1, a, s);
    cout << s.x << " " << s.y << endl;
    koch(d-1, s, u);
    cout << u.x << " " <<  u.y << endl;
    koch(d-1, u, t);
    cout << t.x << " " <<  t.y << endl;
    koch(d-1, t, b);
}

int main() {
    cout << fixed << setprecision(12) << endl;
    point a, b;
    int n; cin >> n;

    a.x = 0.0;
    a.y = 0.0;
    b.x = 100.0;
    b.y = 0.0;

    cout << a.x << " " << a.y << endl;
    koch(n, a, b);
    cout << b.x << " " << b.y << endl;

    return 0;
}