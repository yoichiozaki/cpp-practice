#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    long long K;
    cin >> K;
    long long N = S.size();

    vector<long long> cnt(N + 1);
    for (long long i = 0; i < N; i++)
    {
        if (S[i] == '.')
            cnt[i + 1] = cnt[i] + 1;
        else
            cnt[i + 1] = cnt[i];
    }

    long long ans = 0;
    long long right = 0;
    for (long long left = 0; left < N; left++)
    {
        while (right < N && cnt[right + 1] - cnt[left] <= K)
            right += 1;
        ans = max(ans, right - left);
    }
    cout << ans << endl;
    return 0;
}