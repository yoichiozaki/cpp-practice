#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    long long D; cin >> D;
    vector<long long> A(N), B(M);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    while(1) {
        if ((N == 0) || (M == 0)) {
            cout << -1 << endl;
            return 0;
        }

        long long x = A.back(), y = B.back();
        if (abs(x - y) <= D) {
            cout << x + y << endl;
            return 0;
        }

        if (x > y) A.pop_back(), N--;
        else B.pop_back(), M--;
    }
    return 0;
}