#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    while (cin >> n, n)
    {
        vector<pair<int, ll>> score(4001);
        vector<int> check(4001);
        for (int i = 1; i < 4001; i++)
            score[i] = make_pair(-1, 0LL), check[i] = -1;
        int idx = 0;
        for (int i = 1; i <= n; i++)
        {
            int id;
            ll price, amount;
            cin >> id >> price >> amount;
            if (check[id] == -1) // 初出
            {
                score[idx].first = id;
                score[idx].second = price * amount;
                check[id] = idx;
                idx++;
            }
            else
                score[check[id]].second += price * amount;
        }
        int count = 0;
        for (int i = 0; i <= idx; i++)
        {
            if (1000000 <= score[i].second)
            {
                cout << score[i].first << endl;
                count++;
            }
        }
        if (count == 0)
            cout << "NA" << endl;
    }
    return 0;
}