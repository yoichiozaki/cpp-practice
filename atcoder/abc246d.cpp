#include <bits/stdc++.h>

using namespace std;

long long f(long long a, long long b) {
    return a*a*a + a*a*b + a*b*b + b*b*b;
}

int main() {
    long long N; cin >> N;
    long long X = 8e18;
    long long j = 1000000;
    for (long long i = 0; i <= 1000000; i++) {
        while (N <= f(i, j) && 0 <= j) {
            X = min(X, f(i, j));
            j -= 1;
        }
    }
    cout << X << endl;
    return 0;
}