#include <bits/stdc++.h>
using namespace std;

// DFSで木を走査しながらLISをカウントする

const int MAX_N = 200005;
const int INF = 1001001001;

vector<int> a, ans;
vector<int> tree[MAX_N];
int dp[MAX_N];

void DFS(int v, int p = -1)
{
    int i = lower_bound(dp, dp + MAX_N, a[v]) - dp;
    int old = dp[i];
    dp[i] = a[v];
    ans[v] = i;
    if (p != -1)
        ans[v] = max(ans[v], ans[p]);
    for (int u : tree[v])
    {
        if (u == p)
            continue;
        DFS(u, v);
    }
    dp[i] = old;
}

int main()
{
    int N;
    cin >> N;
    a = ans = vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i = 0; i < MAX_N; i++)
        dp[i] = INF;
    dp[0] = -INF;
    DFS(0);
    for (int i = 0; i < N; i++)
        cout << ans[i] << endl;
    return 0;
}