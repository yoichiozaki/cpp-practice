#include <bits/stdc++.h>

using namespace std;

int main() {
    const int MAX = 200000;
    int N; cin >> N;
    vector<long long> cnt(MAX + 1, 0ll);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        cnt[x] += 1ll;
    } 
    long long ans = 0;
    for (int q = 1; q <= MAX; q++) {
        for (int r = 1; q * r <= MAX; r++) {
            ans += cnt[q] * cnt[r] * cnt[q * r];
        }
    }
    cout << ans << endl;
    return 0;
}