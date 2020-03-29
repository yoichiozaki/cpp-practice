#include <bits/stdc++.h>
using namespace std;

long long nC2(long long n) {
    return n*(n-1)/2;
}

int main() {
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += nC2(cnt[i]);
    }
    for (int i = 0; i < n; i++) {
        long long ans = total;
        ans -= nC2(cnt[a[i]]);
        cnt[a[i]]--;
        ans += nC2(cnt[a[i]]);
        cout << ans << endl;
        cnt[a[i]]++;
    }
    return 0;
}