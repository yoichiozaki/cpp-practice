#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    for (int _ = 0; _ < T; _++) {
        long long N; cin >> N;
        long long p = 0;
        long long q = 0;
        for (long long i = 2; i * i * i <= N; i++) {
            if (N % i != 0) continue;
            if ((N / i) % i == 0) {
                p = i;
                q = N / i / i;
            } else {
                q = i;
                p = (long long) round(sqrt(N / i));
            }
            break;
        }
        cout << p << " " << q << endl;
    }
    return 0;
}