#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 1; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<int> DP(N, 0);
    for (int i = 1; i < N; i++) DP[i] = DP[A[i]] + 1;
    cout << DP[N - 1] << endl;
    return 0;
}