#include <bits/stdc++.h>

using namespace std;

int main() {
    int Q; cin >> Q;
    multiset<long long> s, t;
    for (int i = 0; i < Q; i++) {
        int command; cin >> command;
        if (command == 1) {
            long long x; cin >> x;
            s.insert(x);
            t.insert(-x);
        } else if (command == 2) {
            long long x, k; cin >> x >> k;
            auto iter = t.lower_bound(-x);
            for (int j = 1; j < k; j++) {
                if (iter != t.end()) {
                    iter++;
                }
            }
            cout << (iter == t.end() ? -1 : -*iter) << endl;
        } if (command == 3) {
            long long x, k; cin >> x >> k;
            auto iter = s.lower_bound(x);
            for (int j = 1; j < k; j++) {
                if (iter != s.end()) {
                    iter++;
                }
            }
            cout << (iter == s.end() ? -1 : *iter) << endl;
        }
    }
    return 0;
}