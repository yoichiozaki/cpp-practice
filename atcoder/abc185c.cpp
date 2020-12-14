#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> combination(long long n, long long r)
{
    vector<vector<long long>> v(n + 1, vector<long long>(n + 1, 0LL));
    for (int i = 0; i < v.size(); i++)
    {
        v[i][0] = 1LL;
        v[i][i] = 1LL;
    }

    for (int j = 1; j < v.size(); j++)
    {
        for (int k = 1; k < j; k++)
        {
            v[j][k] = v[j - 1][k - 1] + v[j - 1][k];
        }
    }

    return v;
}

int main()
{
    long long L;
    cin >> L;
    auto ans = combination(L - 1, 11LL);
    cout << ans[L - 1][11] << endl;
    return 0;
}