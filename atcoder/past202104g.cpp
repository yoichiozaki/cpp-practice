#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<pair<int, int>>> G(N);
    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        G[A].push_back(make_pair(B, C));
        G[B].push_back(make_pair(A, C));
    }

    vector<bool> has_visited(N, false);
    has_visited[0] = true;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    for (auto x : G[0])
    {
        que.push(make_pair(x.second, x.first));
    }

    int ans = 1;

    for (int _ = 0; _ < Q; _++)
    {
        int X;
        cin >> X;
        vector<pair<int, int>> next_cities;
        while (!que.empty() && que.top().first <= X)
        {
            auto current_city = que.top();
            que.pop();

            if (has_visited[current_city.second])
                continue;

            has_visited[current_city.second] = true;
            ans += 1;

            for (auto candidate : G[current_city.second])
            {
                next_cities.push_back(make_pair(candidate.second, candidate.first));
            }
        }
        for (auto next_city : next_cities)
        {
            que.push(next_city);
        }
        cout << ans << endl;
    }

    return 0;
}