#include <bits/stdc++.h>
using namespace std;

int main() {
  int W; cin >> W;
  int N, K; cin >> N >> K;
  int width[N+1], value[N+1];
  for (int i = 1; i <= N; i++) {
    cin >> width[i] >> value[i];
  }

  int dp[N+1][K+1][W+1];
  memset(dp, 0, sizeof(dp));

  for (int k = 1; k <= N; k++) {
    for (int j = 1; j <= K; j++) {
      for (int i = 1; i <= W; i++) {
        if (0 <= i - width[k]) {
          dp[k][j][i] = max(dp[k][j][i], dp[k-1][j-1][i-width[k]] + value[k]);
        }
        dp[k][j][i] = max(dp[k][j][i], dp[k-1][j-1][i]);
      }
    }
  }

  cout << dp[N][K][W] << endl;
  return 0;
}