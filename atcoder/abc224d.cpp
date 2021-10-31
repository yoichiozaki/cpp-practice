#include <bits/stdc++.h>

using namespace std;

int main()
{
    int M;
    cin >> M;

    vector<vector<int>> G(9, vector<int>(0, 0));
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    string init_state = "999999999";
    for (int i = 0; i < 8; i++)
    {
        int p;
        cin >> p;
        p--;
        init_state[p] = (i + 1) + '0';
    }

    queue<string> Q;
    Q.push(init_state);
    map<string, int> dist;
    dist[init_state] = 0;

    while (Q.size() != 0)
    {
        string state = Q.front();
        Q.pop();

        int v;
        for (int i = 0; i < 9; i++)
        {
            if (state[i] == '9')
            {
                v = i;
                break;
            }
        }

        for (auto u : G[v])
        {
            string next_state = state;
            swap(next_state[u], next_state[v]);
            if (dist.count(next_state) != 0)
                continue;
            dist[next_state] = dist[state] + 1;
            Q.push(next_state);
        }
    }

    if (dist.count("123456789") == 0)
        cout << -1 << endl;
    else
        cout << dist["123456789"] << endl;

    return 0;
}