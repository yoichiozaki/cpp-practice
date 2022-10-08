#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, S; cin >> N >> S;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    vector<vector<bool>> memo(N + 1, vector<bool>(S + 1, false));
    memo[0][0] = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= S; j++) {
            if (memo[i][j]) {
                if (j + A[i] <= S) {
                    memo[i + 1][j + A[i]] = true;
                }
                if (j + B[i] <= S) {
                    memo[i + 1][j + B[i]] = true;
                }
            }
        }
    }
    if (memo[N][S]) {
        cout << "Yes" << endl;
        string path(N, 'H');
        for (int i = N - 1; i >= 0; i--) {
            if (S >= A[i] && memo[i][S - A[i]]) {
                path[i] = 'H';
                S -= A[i];
            } else {
                path[i] = 'T';
                S -= B[i];
            }
        }
        cout << path << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}