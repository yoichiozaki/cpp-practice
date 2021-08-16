#include <bits/stdc++.h>

using namespace std;

const long long inf = LONG_LONG_MAX / 2;

int main()
{
    int N;
    cin >> N;
    vector<int> S(N, 0);
    for (int i = 0; i < N; i++)
        cin >> S[i];

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    for (int i = 0; i < N; i++)
    {
        long long T;
        cin >> T;
        pq.push(make_pair(T, i));
    }

    vector<long long> ans(N, inf);

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        long long T = p.first;
        int X = p.second;
        if (ans[X] < T)
            continue;
        ans[X] = T;
        pq.push(make_pair(T + S[X], (X + 1) % N));
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}