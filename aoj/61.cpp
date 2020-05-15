#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p, s;
    char comma;
    vector<pair<int, int>> m;
    while (cin >> p >> comma >> s)
    {
        if (p == 0 && s == 0)
            break;
        m.push_back(make_pair(s, p));
    }
    sort(m.begin(), m.end(), greater<pair<int, int>>());
    vector<int> rank(105);
    int k = 1;
    rank[m[0].second] = k;
    for (int i = 1; i < m.size(); i++)
    {
        if (m[i - 1].first != m[i].first)
            k++;
        rank[m[i].second] = k;
    }
    int q;
    while (cin >> q)
    {
        cout << rank[q] << endl;
    }
    return 0;
}