#include <bits/stdc++.h>

using namespace std;

int N;
long long Sx, Sy, Tx, Ty;
long long X[3005], Y[3005], R[3005];
vector<int> G[3005];

int S, T;
bool has_visited[3005];

bool dfs(int v) {
    has_visited[v] = true;
    if (v == T) {
        return true;
    }
    for (auto u: G[v]) {
        if (has_visited[u]) {
            continue;
        }
        if (dfs(u)) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N;
    cin >> Sx >> Sy >> Tx >> Ty;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i] >> R[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            long long d = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
            if (d > (R[i] + R[j]) * (R[i] + R[j])) {
                continue;
            }
            if (d < (R[i] - R[j]) * (R[i] - R[j])) {
                continue;
            }
            G[i].push_back(j);
            G[j].push_back(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        if ((X[i] - Sx) * (X[i] - Sx) + (Y[i] - Sy) * (Y[i] - Sy) == R[i] * R[i]) {
            S = i;
        }
        if ((X[i] - Tx) * (X[i] - Tx) + (Y[i] - Ty) * (Y[i] - Ty) == R[i] * R[i]) {
            T = i;
        }
    }

    if (dfs(S)) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}