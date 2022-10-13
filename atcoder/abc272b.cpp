#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<bool>> check(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        int K; cin >> K;
        vector<int> A(K);
        for (auto &v : A) cin >> v, v--;
        for (int j = 0; j < (int)A.size() - 1; j++) {
            for (int k = j + 1; k < (int)A.size(); k++) {
                check[A[j]][A[k]] = true;
            }
        }
    }
    bool ans = true;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ans &= check[i][j];
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}