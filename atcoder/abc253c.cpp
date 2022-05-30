#include <bits/stdc++.h>

using namespace std;

int main() {
    int Q; cin >> Q;
    multiset<int> s;
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            s.insert(x);
        } else if (t == 2) {
            int x, c; cin >> x >> c;
            while (c-- && s.find(x) != s.end()) {
                s.erase(s.find(x));
            }
        } else {
            cout << *s.rbegin() - *s.begin() << endl;
        }
    }
    return 0;
}