#include <bits/stdc++.h>

using namespace std;

long long f(long long n) {
    return n * (n + 1ll) / 2ll;
}

int main() {
    long long N, A, B; cin >> N >> A >> B;
    long long L = A * B / __gcd(A, B);
    cout << f(N) - A * f(N / A) - B * f(N / B) + L * f(N / L) << endl;
    return 0;
}