#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, X; cin >> N >> X;
    int A[50], B[50];
    bool dp[51][10001];
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= X; j++) {
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= X; j++) {
            for (int k = 0; k <= B[i]; k++) {
                if (j >= A[i] * k) {
                    if (dp[i][j - A[i] * k]) {
                        dp[i+1][j] = true;
                    }
                }
            }
        }
    }
    if (dp[N][X]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}