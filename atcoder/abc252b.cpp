#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N), B(K);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < K; i++) cin >> B[i];
    int m = 0;
    for (int i = 0; i < N; i++) m = max(m, A[i]);
    for (int i = 0; i < K; i++) {
        if (A[B[i] - 1] == m) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}