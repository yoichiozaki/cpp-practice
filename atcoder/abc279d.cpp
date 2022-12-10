#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b; cin >> a >> b;
    auto func = [&](long long n) -> double {
        return (double) a / sqrt(n + 1) + (double) b * n;
    };
    long long left = 0, right = a / b;
    while (2 < right - left) {
        long long m1 = (left * 2 + right) / 3;
        long long m2 = (left + right * 2) / 3;
        if (func(m1) > func(m2)) left = m1;
        else right = m2;
    }
    double ans = a;
    for (long long i = left; i <= right; i++) {
        ans = min(ans, func(i));
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}