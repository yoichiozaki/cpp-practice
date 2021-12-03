#include <bits/stdc++.h>

using namespace std;

int N, M;

bool has_visited[1 << 18];
vector<int> G[1 << 18];
vector<int> RG[1 << 18];
vector<int> post_order;
long long cnt = 0;

void DFS(int node)
{
    has_visited[node] = true;
    for (int neighbor : G[node])
    {
        if (!has_visited[neighbor])
            DFS(neighbor);
    }
    post_order.push_back(node);
}

void RDFS(int node)
{
    has_visited[node] = true;
    cnt += 1;
    for (int neighbor : RG[node])
    {
        if (!has_visited[neighbor])
            RDFS(neighbor);
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int A, B;
        cin >> A >> B;
        G[A].push_back(B);
        RG[B].push_back(A);
    }

    for (int i = 1; i <= N; i++)
        has_visited[i] = false;

    for (int node = 1; node <= N; node++)
    {
        if (!has_visited[node])
            DFS(node);
    }

    reverse(post_order.begin(), post_order.end());
    long long ans = 0;

    for (int i = 1; i <= N; i++)
        has_visited[i] = false;

    for (int node : post_order)
    {
        if (has_visited[node])
            continue;
        cnt = 0;
        RDFS(node);
        ans += cnt * (cnt - 1LL) / 2LL;
    }

    cout << ans << endl;

    return 0;
}