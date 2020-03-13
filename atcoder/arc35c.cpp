#include <bits/stdc++.h>
using namespace std;

const int INF = 1001001001;
int dp[405][405];
int N, M;

void warshall() {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

long long sum_of_minimum() {
    long long ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            ret += dp[i][j];
        }
    }
    return ret;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = INF;
        }
        dp[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        dp[a][b] = c;
        dp[b][a] = c;
    }
    warshall();
    int K; cin >> K;
    for (int k = 0; k < K; k++) {
        int x, y, z; cin >> x >> y >> z;
        x--; y--;
        dp[x][y] = min(dp[x][y], z);
        dp[y][x] = min(dp[y][x], z);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = min(dp[i][j], dp[i][x] + dp[x][y] + dp[y][j]);
                dp[i][j] = min(dp[i][j], dp[i][y] + dp[y][x] + dp[x][j]);
            }
        }
        cout << sum_of_minimum() << endl;
    }
    return 0;
}