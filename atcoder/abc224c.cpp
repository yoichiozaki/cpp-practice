#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<long long, long long>> P(N);
    for (int i = 0; i < N; i++)
    {
        long long X, Y;
        cin >> X >> Y;
        P[i] = make_pair(X, Y);
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j; k < N; k++)
            {
                auto Pi = P[i];
                auto Pj = P[j];
                auto Pk = P[k];
                if ((Pj.first - Pi.first) * (Pk.second - Pi.second) - (Pk.first - Pi.first) * (Pj.second - Pi.second) != 0)
                    ans += 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}