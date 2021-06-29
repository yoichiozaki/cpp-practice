#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(2 * N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        A[i + N] = A[i];
    }

    vector<int> accum(2 * N, 0);
    accum[0] = A[0];
    for (int i = 1; i < 2 * N; i++)
    {
        accum[i] = accum[i - 1] + A[i];
    }

    int total = accum[2 * N - 1];
    int ans = total;
    for (int i = 0; i < N; i++)
    {
        int pos = upper_bound(accum.begin(), accum.end(), total / 2 + accum[i]) - accum.begin();
        ans = min(ans, abs(total - (accum[pos] - accum[i]) * 2));
        ans = min(ans, abs(total - (accum[pos - 1] - accum[i]) * 2));
    }

    cout << ans << endl;
    return 0;
}