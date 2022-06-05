#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<int>> B(K);
    for (int i = 0; i < N; i++) B[i % K].push_back(A[i]);
    for (int i = 0; i < K; i++) sort(B[i].rbegin(), B[i].rend());
    sort(A.begin(), A.end());
    vector<int> C;
    for (int i = 0; i < N; i++) {
        C.push_back(B[i % K].back());
        B[i % K].pop_back();
    }
    if (A == C) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}