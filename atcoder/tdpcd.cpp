#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    long long D; cin >> D;
    int two = 0, three = 0, five = 0;

    // サイコロの出目は1, 2, 3, 4, 5, 6なのでその積を素因数分解すると2^a * 3^b * 5^cの形になっているはずなので，それ以外の素因数を持っているDなら確率は0

    cout << fixed << setprecision(12);

    while (1 < D) {
        if (D%2 == 0) {
            two++;
            D /= 2;
        }
        if (D%3 == 0) {
            three++;
            D /= 3;
        }
        if (D%5 == 0) {
            five++;
            D /= 5;
        }
        if (D%5 != 0 && D%2 != 0 && D%3 != 0 && D != 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    // dp[i][j][k][l]: サイコロをi回振ったとき，D(= 2^j * 3^k * 5^l)で割り切れる確率
    double dp[N+1][two+1][three+1][five+1] = {0};
    dp[0][0][0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= two; j++) {
            for (int k = 0; k <= three; k++) {
                for (int l = 0; l <= five; l++) {
                    dp[i+1][j][k][l]                           += dp[i][j][k][l]/6.0; // i+1回目にサイコロを振ったときの出目が1
                    dp[i+1][min(two, j+1)][k][l]               += dp[i][j][k][l]/6.0; // i+1回目にサイコロを振ったときの出目が2
                    dp[i+1][j][min(three, k+1)][l]             += dp[i][j][k][l]/6.0; // i+1回目にサイコロを振ったときの出目が3
                    dp[i+1][min(two, j+2)][k][l]               += dp[i][j][k][l]/6.0; // i+1回目にサイコロを振ったときの出目が4
                    dp[i+1][j][k][min(five, l+1)]              += dp[i][j][k][l]/6.0; // i+1回目にサイコロを振ったときの出目が5
                    dp[i+1][min(two, j+1)][min(three, k+1)][l] += dp[i][j][k][l]/6.0; // i+1回目にサイコロを振ったときの出目が6
                }
            }
        }
    }

    cout << dp[N][two][three][five] << endl;
    return 0;
}