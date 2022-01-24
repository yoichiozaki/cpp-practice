#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> towns(N);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        towns[i] = {x, y};
    }
    set<pair<int, int>> magic;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            int dx = towns[i].first - towns[j].first;
            int dy = towns[i].second - towns[j].second;
            int gcd = __gcd(dx, dy);
            magic.insert({dx / gcd, dy / gcd});
        }
    }
    cout << magic.size() * 2 << endl;
    return 0;
}