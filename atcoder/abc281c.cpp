#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    long long T; cin >> T;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long remain = T % accumulate(A.begin(), A.end(), 0LL);
    long long elapsed = 0;
    for (int i = 0; i < N; i++) {
        if (elapsed + A[i] > remain) {
            cout << i + 1 << " " << remain - elapsed << endl;
            return 0;;
        }
        elapsed += A[i];
    }
    return 0;
}