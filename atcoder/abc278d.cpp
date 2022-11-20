#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) cin >> A[i];
    int base = 0;
    map<int, long long> mp;
    for (int i = 0; i < N; i++) mp[i] = A[i];
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            base = x;
            mp.clear();
        } else if (t == 2) {
            int i, x; cin >> i >> x;
            mp[i - 1] += x;
        } else if (t == 3) {
            int i; cin >> i;
            cout << base + mp[i - 1] << endl;
        }
    }
    return 0;
}