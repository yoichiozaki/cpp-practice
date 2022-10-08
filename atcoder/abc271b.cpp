#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int L; cin >> L;
        A[i] = vector<int>(L);
        for (int j = 0; j < L; j++) {
            cin >> A[i][j];
        }
    }
    for (int q = 0; q < Q; q++) {
        int S, T; cin >> S >> T;
        cout << A[S - 1][T - 1] << endl;
    }
    return 0;
}