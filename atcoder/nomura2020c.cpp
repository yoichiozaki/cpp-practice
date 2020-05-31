#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    vector<long long> A(N + 1, 0LL), B(N + 2, 0LL);
    for (int i = 0; i < N + 1; i++)
        cin >> A[i];
    for (int i = N; 0 <= i; i--)
        B[i] = B[i + 1] + A[i];
    if (A[0] == 1)
    {
        if (N == 0)
            cout << 1 << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    if (A[0] != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    long long ans = 1LL, now = 1LL;
    for (int i = 1; i <= N; i++)
    {
        now = (now - A[i - 1]) * 2;
        if (now < 0 || now < A[i])
        {
            cout << -1 << endl;
            return 0;
        }
        now = min(now, B[i]);
        ans += now;
    }
    cout << ans << endl;
    return 0;
}