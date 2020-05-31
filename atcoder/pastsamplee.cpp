#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> P(M), Y(M);
    map<int, vector<int>> mp;
    for (int i = 0; i < M; i++)
    {
        cin >> P[i] >> Y[i];
        mp[P[i]].emplace_back(Y[i]);
    }
    for (auto &m : mp)
        sort(m.second.begin(), m.second.end());
    for (int i = 0; i < M; i++)
    {
        auto &v = mp[P[i]];
        int x = lower_bound(v.begin(), v.end(), Y[i]) - v.begin();
        cout << setw(6) << setfill('0') << P[i]
             << setw(6) << setfill('0') << x + 1 << endl;
    }
    return 0;
}