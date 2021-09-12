#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    queue<int> que;
    vector<queue<int>> cylinders(M);
    vector<vector<int>> top_color(N);

    for (int i = 0; i < M; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            cylinders[i].push(a - 1);
        }
        top_color[cylinders[i].front()].push_back(i);
    }

    for (int i = 0; i < N; i++)
    {
        if (top_color[i].size() == 2)
        {
            que.push(i);
        }
    }

    while (!que.empty())
    {
        int top = que.front();
        que.pop();
        for (auto cid : top_color[top])
        {
            cylinders[cid].pop();
            if (!cylinders[cid].empty())
            {
                top_color[cylinders[cid].front()].push_back(cid);
                if (top_color[cylinders[cid].front()].size() == 2)
                {
                    que.push(cylinders[cid].front());
                }
            }
        }
    }

    for (auto cylinder : cylinders)
    {
        if (!cylinder.empty())
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}