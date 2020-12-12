#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    vector<int> S(N, 0);
    S[0] = A[0];
    for (int i = 1; i < N; i++)
        S[i] = S[i - 1] + A[i];
    vector<int> P(N, 0);
    vector<int> Q(N, 0);
    for (int i = 0; i < N; i++)
    {
        P[i] = S[i];
        Q[i] = *max_element(S.begin(), S.begin() + i);
    }

    int ans = 0;
    int now = 0;
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, now + Q[i]);
        now += P[i];
    }

    cout << ans << endl;
    return 0;
}