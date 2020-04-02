#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int x, y; cin >> x >> y;
    int a, b, c; cin >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    for (int i = 0; i < a; i++) cin >> p[i];
    for (int i = 0; i < b; i++) cin >> q[i];
    for (int i = 0; i < c; i++) cin >> r[i];
    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    vector<int> d;
    for (int i = 0; i < x; i++) d.push_back(p[i]);
    for (int i = 0; i < y; i++) d.push_back(q[i]);
    for (int i = 0; i < c; i++) d.push_back(r[i]);
    sort(d.rbegin(), d.rend());
    ll ans = 0;
    for (int i = 0; i < x+y; i++) ans += d[i];
    cout << ans << endl;
    return 0;
}