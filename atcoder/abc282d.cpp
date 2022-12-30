#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

long long N, M;
vector<int> G[200005];
int color[200005];

P dfs(int v, int p, int c) {
    P ret = P(0, 0);
    color[v] = c;

    if (c == 1) ret.first += 1;
    else ret.second += 1;

    for (auto u: G[v]) {
        if (u == p || color[u] == -c) continue;
        if (color[u] == c) return P(-1, -1);
        P res = dfs(u, v, -c);
        if (res.first == -1) return P(-1, -1);
        ret.first += res.first;
        ret.second += res.second;
    }
    return ret;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll ans = N * (N - 1) / 2 - M;
    for (int i = 1; i <= N; i++) {
        if (!color[i]) {
            P res = dfs(i, -1, 1);
            if (res.first == -1) {
                cout << 0 << endl;
                return 0;
            }
            ans -= res.first * (res.first - 1) / 2;
            ans -= res.second * (res.second - 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}