#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N; cin >> N;

    vector<vector<ll>> D(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> D[i][j];
        }
    }

    vector<vector<ll>> S(N+1, vector<ll>(N+1, 0)); // S[i][j]: 領域[0, i)x[0, j)における美味しさの総和
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            S[i+1][j+1] = S[i+1][j] + S[i][j+1] - S[i][j] + D[i][j];
        }
    }

    vector<long long> val(N*N+1, 0); // val[i]: 面積がiとなる領域における美味しさの総和の最大値
    for (int x1 = 0; x1 < N; x1++) {
        for (int x2 = x1+1; x2 <= N; x2++) {
            for (int y1 = 0; y1 < N; y1++) {
                for (int y2 = y1+1; y2 <= N; y2++) {
                    ll area = (x2-x1) * (y2-y1);
                    ll sum = S[x2][y2] - S[x2][y1] - S[x1][y2] + S[x1][y1];
                    val[area] = max(val[area], sum);
                }
            }
        }
    }

    // val[i]: 面積i以下の長方形領域における美味しさの総和の最大値
    for (int i = 0; i < N*N; i++) {
        val[i+1] = max(val[i+1], val[i]);
    }

    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        long long P; cin >> P;
        cout << val[P] << endl;
    }

    return 0;
}