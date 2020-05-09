#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, vector<pair<int, int>>> table;
    for (int i = 0; i < n; i++)
    {
        string s;
        int p;
        cin >> s >> p;
        table[s].push_back(make_pair(p, i + 1));
    }
    for (auto item : table)
    {
        vector<pair<int, int>> shops = item.second;
        sort(shops.begin(), shops.end(), greater<pair<int, int>>());
        for (auto s : shops)
        {
            cout << s.second << endl;
        }
    }

    return 0;
}