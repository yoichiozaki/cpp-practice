#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N, 0);
    int mod = 1000000007;
    long long csum = 0LL;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        csum += A[i];
        csum %= mod;
    }

    long long ans = 0LL;

    for (int i = 0; i < N; i++)
    {
        csum -= A[i];
        if (csum < 0)
            csum += mod;
        ans += A[i] * csum;
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}