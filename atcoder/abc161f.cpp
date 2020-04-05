#include <bits/stdc++.h>
using namespace std;

vector<long long> enumDivisor(long long n) {
    vector<long long> res;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) continue;
        res.push_back(i);
        if (i * i != n) res.push_back(n / i);
    }
    return res;
}

int main() {
    long long n; cin >> n;
    int ans = 0;
    for (long long x : enumDivisor(n)) {
        if (x == 1) continue;
        long long tmp = n;
        while (tmp % x == 0) tmp /= x;
        tmp %= x;
        if (tmp == 1) ans++;
    }
    ans += enumDivisor(n-1).size() - 1;
    cout << ans << endl;
    return 0;
}