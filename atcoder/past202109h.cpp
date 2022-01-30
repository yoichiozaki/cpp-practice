#include <bits/stdc++.h>

using namespace std;

// 木上の最短距離は普通にたどれば求まる

long long N, X;
vector<vector<pair<long long, long long>>> T;
bool ok = false;

void DFS(long long curr, long long par, long long dist)
{
    if (dist == X)
        ok = true;
    for (int i = 0; i < T[curr].size(); i++)
    {
        long long nxt = T[curr][i].first;
        long long weight = T[curr][i].second;
        if (nxt == par)
            continue;
        DFS(nxt, curr, dist + weight);
    }
}

int main()
{
    cin >> N >> X;
    T.resize(N);
    for (int i = 0; i < N - 1; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        T[a].emplace_back(b, c);
        T[b].emplace_back(a, c);
    }
    for (long long i = 0; i < N; i++)
        DFS(i, -1ll, 0ll);
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}