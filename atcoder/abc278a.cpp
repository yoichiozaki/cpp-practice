#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if (K <= i) {
            A[i - K] = a;
        } 
    }
    for (int i = 0; i < N; i++) {
        cout << A[i] << (i == N - 1 ? "\n" : " ");
    }
    return 0;
}