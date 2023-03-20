#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> U(M), V(M);
    for (int i = 0; i < M; i++) cin >> U[i] >> V[i];
    for (int i = 0; i < M; i++) {
        if (!(1 <= U[i] && U[i] <= N && 1 <= V[i] && V[i] <= N)) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 0; i < M; i++) {
        if (U[i] == V[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    set<pair<int, int>> S;
    for (int i = 0; i < M; i++) {
        if (U[i] > V[i]) swap(U[i], V[i]);
        if (S.count({U[i], V[i]}) != 0) {
            cout << "No" << endl;
            return 0;
        }
        S.insert({U[i], V[i]});
    }
    cout << "Yes" << endl;
    return 0;
}