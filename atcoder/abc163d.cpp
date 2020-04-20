#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

int main() {
    long long n, k; cin >> n >> k;
    long long ans = 0;
    for (long long i = k; i <= n+1; i++) {
        long long minimum = i*(i-1)/2; // 下からi個
        long long maximum = (n + (n-i+1)) * i / 2; // 上からi個
        ans = (ans + (maximum - minimum + 1)) % mod;
    }
    cout << ans << endl;
    return 0;
}