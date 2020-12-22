#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    sort(A.begin() + 1, A.end());
    vector<long long>
        S(N + 1, 0);
    S[1] = A[1];
    for (int i = 2; i <= N; i++)
        S[i] += S[i - 1] + A[i];
    long long ans = 0;
    for (int i = 1; i <= N - 1; i++)
    {
        ans += (S[N] - S[i]) - (N - i) * A[i];
    }
    cout << ans << endl;
    return 0;
}