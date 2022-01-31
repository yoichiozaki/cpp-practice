#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    string S;
    cin >> S;

    long long ans = 0;
    long long n = 0;
    for (long long j = 0; j < N; j++)
    {
        if (0 < j && S[j] == S[j - 1])
            n += 1;
        else
            n = 0;
        ans += n;
    }
    cout << ans << endl;
    return 0;
}