#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

const long long MOD = 1000000007;

vector<long long> dist;
vector<long long> cnt;
queue<int> suspended;
void BFS(const Graph &G, int v)
{
    dist[v] = 0LL;
    cnt[v] = 1LL;
    suspended.push(v);

    while (!suspended.empty())
    {
        int u = suspended.front();
        suspended.pop();
        for (auto w : G[u])
        {
            if (dist[w] != -1LL)
            {
                if (dist[w] == dist[u] + 1)
                {
                    cnt[w] = (cnt[w] % MOD + cnt[u] % MOD) % MOD;
                }
                continue;
            }
            else
            {
                dist[w] = dist[u] + 1LL;
                cnt[w] = cnt[u];
                suspended.push(w);
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u -= 1LL;
        v -= 1LL;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dist.assign(N, -1LL);
    cnt.assign(N, 0LL);

    BFS(G, 0);

    if (dist[N - 1] == -1LL)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << cnt[N - 1] << endl;
    }
    return 0;
}