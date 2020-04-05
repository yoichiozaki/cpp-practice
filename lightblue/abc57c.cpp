#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    int minlen = 15;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i != 0) continue;
        long long j = n / i;
        string si = to_string(i);
        string sj = to_string(j);
        int len = (si.size() < sj.size() ? sj.size() : si.size());
        minlen = min(minlen, len);
    }
    cout << minlen << endl;
    return 0;
}