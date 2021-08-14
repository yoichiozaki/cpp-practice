#include <bits/stdc++.h>

using namespace std;

const int inf = INT_MAX / 2;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N + 5, 0);
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    vector<int> S(N + 5, 0);
    for (int i = 1; i <= N; i++)
    {
        if (A[i] == 0)
            S[i] = S[i - 1] + 1;
        else
            S[i] = S[i - 1];
    }

    vector<int> T(N + 5, 0);
    for (int i = N; 0 <= i; i--)
    {
        if (A[i] == 1)
            T[i] = T[i + 1] + 1;
        else
            T[i] = T[i + 1];
    }

    int ans = inf;
    for (int i = 0; i <= N; i++)
    {
        ans = min(ans, S[i] + T[i + 1]);
    }

    cout << ans << endl;
    return 0;
}