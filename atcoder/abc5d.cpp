#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<long long>> D(N, vector<long long>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> D[i][j];
        }
    }

    vector<vector<long long>> S(N+1, vector<long long>(N+1, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            S[i+1][j+1] = S[i][j+1] + S[i+1][j] - S[i][j] + D[i][j];
        }
    }

    vector<long long> val(N*N+1, 0); // val[v]: 面積がvとなる長方形領域における総和の最大値
    for (int x1 = 0; x1 < N; x1++) {
        for (int x2 = x1+1; x2 <= N; x2++) {
            for (int y1 = 0; y1 < N; y1++) {
                for (int y2 = y1+1; y2 <= N; y2++) {
                    long long area = (x2 - x1) * (y2 - y1);
                    long long sum = S[x2][y2] - S[x1][y2] - S[x2][y1] + S[x1][y1];
                    val[area] = max(val[area], sum);
                }
            }
        }
    }

    for (int v = 0; v < N*N; v++) {
        val[v+1] = max(val[v+1], val[v]); // 面積がv以下の長方形領域の総和の最大値
    }

    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        long long P; cin >> P;
        cout << val[P] << endl;
    }
}