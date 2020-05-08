#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    vector<long long> P(N);
    for (long long i = 0; i < N; i++)
    {
        cin >> P[i];
    }
    long long ans = 0;
    long long mi = P[0];
    for (int i = 0; i < N; i++)
    {
        if (P[i] <= mi)
        {
            ans++;
            mi = min(mi, P[i]);
        }
    }
    cout << ans << endl;
    return 0;
}