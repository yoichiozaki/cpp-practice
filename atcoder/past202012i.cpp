#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

const int inf = INT_MAX / 2;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> H(N, 0);
    for (int i = 0; i < N; i++)
        cin >> H[i];

    vector<int> ans(N, inf);

    queue<int> Q;

    vector<int> C(K, 0);
    for (int i = 0; i < K; i++)
    {
        cin >> C[i];
        C[i] -= 1;
        ans[C[i]] = 0;
        Q.push(C[i]);
    }

    Graph G(N);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (H[a] < H[b])
        {
            G[a].push_back(b);
        }
        else
        {
            G[b].push_back(a);
        }
    }

    while (!Q.empty())
    {
        int current = Q.front();
        Q.pop();

        for (auto to : G[current])
        {
            if (ans[to] == inf)
            {
                ans[to] = ans[current] + 1;
                Q.push(to);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (ans[i] == inf)
            cout << -1 << endl;
        else
            cout << ans[i] << endl;
    }
    return 0;
}