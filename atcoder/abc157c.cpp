#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, a, b;
    cin >> N >> M;
    vector<pair<int, int>> P(M);
    for (int i = 0; i < M; i++)
    {
        cin >> P[i].first >> P[i].second;
    }
    for (int j = 0; j < 1000; j++)
    {
        int k = 1;
        int Nj = j / 10;
        vector<int> d(1, j % 10);
        while (Nj)
        {
            k++;
            d.push_back(Nj % 10);
            Nj /= 10;
        }
        if (k != N)
            continue;
        bool ok = true;
        reverse(d.begin(), d.end());
        for (int i = 0; i < M; i++)
        {
            if (d[P[i].first - 1] != P[i].second)
                ok = false;
        }
        if (ok)
        {
            cout << j << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}
