#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N; cin >> N;
    N %= 998244353;
    if (N < 0LL) N += 998244353;
    cout << N << endl;
    return 0;
}