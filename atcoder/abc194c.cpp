#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    vector<long long> A(N, 0);
    for (long long i = 0; i < N; i++)
        cin >> A[i];
    vector<long long> cnt(410, 0);
    for (auto a : A)
    {
        cnt[a + 200]++;
    }
    long long ans = 0;
    for (int i = 0; i <= 400; i++)
    {
        for (int j = 0; j <= 400; j++)
        {
            ans += cnt[i] * cnt[j] * abs(i - j) * abs(i - j);
        }
    }
    cout << ans / 2 << endl;
    return 0;
}