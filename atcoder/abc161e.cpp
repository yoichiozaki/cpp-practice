#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, c; cin >> n >> k >> c;
    string s; cin >> s;
    auto getPositions = [&]() {
        vector<int> res;
        for (int i = 0; i < n && res.size() < k;) {
            if (s[i] == 'o') {
                res.push_back(i);
                i += c + 1;
            } else {
                i += 1;
            }
        }
        return res;
    };
    vector<int> l, r;
    l = getPositions();
    reverse(s.begin(), s.end());
    r = getPositions();
    for (int i = 0; i < k; i++) r[i] = n - 1 - r[i];

    vector<int> ll(n+1, -1), rr(n+1, -1);
    for (int i = 0; i < l.size(); i++) ll[l[i]+1] = l[i]+1;
    for (int i = 0; i < r.size(); i++) rr[r[i]+1] = r[i]+1;

    for (int x = 1; x <= n; x++) {
        if (ll[x] != -1 && rr[x] != -1 && ll[x] == rr[x]) cout << ll[x] << endl;
    }
    return 0;
}