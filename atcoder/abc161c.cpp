#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k; cin >> n >> k;
    long long a = n % k;
    long long ans = min(a, k - a);
    cout << ans << endl;
    return 0;
}