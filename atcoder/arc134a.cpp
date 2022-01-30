#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, L, W;
    cin >> N >> L >> W;
    long long curr = 0;
    vector<long long> A(N + 1, L);
    for (long long i = 0; i < N; i++)
        cin >> A[i];
    long long ans = 0;
    for (auto a : A)
    {
        if (curr < a)
        {
            ans += (a - curr + W - 1) / W; // 足りない部分を覆う
        }
        curr = a + W;
    }
    cout << ans << endl;

    return 0;
}