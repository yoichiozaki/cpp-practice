#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p; cin >> n >> p;
    string s; cin >> s;

    if (p == 2 || p == 5) {
        long long ans = 0;
        for (int right = 0; right < n; right++) {
            if ((s[right]-'0')%p == 0) {
                ans += right+1;
            }
        }
        cout << ans << endl;
        return 0;
    }

    vector<int> d(n+1);
    int base = 1;
    for (int i = n-1; 0 <= i; i--) {
        int a = (s[i]-'0')* base % p;
        d[i] = (d[i+1]+a) % p;
        base *= 10; base %= p; // オーバーフロー対策
    }
    vector<int> cnt(p);
    long long ans = 0;
    for (int i = n; 0 <= i; i--) {
        ans += cnt[d[i]];
        cnt[d[i]]++;
    }
    cout << ans << endl;
    return 0;
}