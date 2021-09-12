#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<string> S(N), T(N);
    for (int _ = 0; _ < N; _++)
        cin >> S[_];
    for (int _ = 0; _ < N; _++)
        cin >> T[_];

    vector<pair<int, int>> spos, tpos;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (S[i][j] == '#')
            {
                spos.push_back(make_pair(i, j));
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (T[i][j] == '#')
            {
                tpos.push_back(make_pair(i, j));
            }
        }
    }

    if (spos.size() != tpos.size())
    {
        cout << "No" << endl;
        return 0;
    }

    sort(tpos.begin(), tpos.end());

    for (int dir = 0; dir < 4; dir++)
    {
        sort(spos.begin(), spos.end());

        bool ok = true;
        int dx = tpos[0].first - spos[0].first;
        int dy = tpos[0].second - spos[0].second;

        for (int i = 0; i < spos.size(); i++)
        {
            if (tpos[i].first - spos[i].first != dx || tpos[i].second - spos[i].second != dy)
            {
                ok = false;
            }
        }

        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }

        for (int i = 0; i < spos.size(); i++)
        {
            spos[i] = make_pair(spos[i].second, N - spos[i].first + 1);
        }
    }

    cout << "No" << endl;
    return 0;
}