#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> tasks;
    for (int i = 0; i < N; i++)
    {
        int A, B;
        cin >> A >> B;
        tasks.push_back(make_pair(A, B));
    }
    vector<vector<int>> tasks_per_day(N + 1, vector<int>(0));
    for (auto t : tasks)
    {
        int a = t.first;
        int b = t.second;
        tasks_per_day[a].push_back(b);
    }
    priority_queue<int> q;
    int ans = 0;
    for (int day = 1; day <= N; day++)
    {
        for (auto gain : tasks_per_day[day])
        {
            q.push(gain);
        }
        ans += q.top();
        q.pop();
        cout << ans << endl;
    }
    return 0;
}