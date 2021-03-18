#include <bits/stdc++.h>
using namespace std;

struct info
{
    int A;
    int P;
    int X;
};

bool by_P(const struct info &p, const struct info &q)
{
    return p.P < q.P;
}

int main()
{
    int N;
    cin >> N;
    vector<info> INFO(N);
    for (int i = 0; i < N; i++)
    {
        struct info _info;
        cin >> _info.A >> _info.P >> _info.X;
        _info.X = max(_info.X - _info.A, 0);
        INFO[i] = _info;
    }
    sort(INFO.begin(), INFO.end(), by_P);
    for (auto _info : INFO)
    {
        if (_info.X != 0)
        {
            cout << _info.P << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}