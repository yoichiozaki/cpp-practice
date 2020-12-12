#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, W;
    cin >> N >> W;
    vector<pair<int, int>> events;

    for (int i = 0; i < N; i++)
    {
        int S, T, P;
        cin >> S >> T >> P;
        events.push_back(make_pair(S, P));
        events.push_back(make_pair(T, -P));
    }

    sort(events.begin(), events.end());

    long long current = 0LL;
    for (auto e : events)
    {
        current += e.second;
        if (W < current)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}