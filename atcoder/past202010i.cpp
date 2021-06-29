#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<long long> accum(2 * N + 1);
    for (int i = 0; i < N; i++)
    {
        accum[i + 1] = accum[i] + A[i];
    }

    for (int i = 0; i < N; i++)
    {
        accum[i + N + 1] = accum[i + N] + A[i];
    }

    accum.emplace_back(1e+18);

    long long ans = 1e+18;

    for (int l = 0; l < N; ++l)
    {
        int r = lower_bound(accum.begin(), accum.end(), accum[l] + accum[N] / 2) - accum.begin();
        ans = min(ans, abs(accum[N] - (accum[r] - accum[l]) * 2));
        ans = min(ans, abs(accum[N] - (accum[r - 1] - accum[l]) * 2));
    }

    cout << ans << endl;
    return 0;
}