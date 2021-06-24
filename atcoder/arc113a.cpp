#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long K;
    cin >> K;
    long long ans = 0;
    for (long long a = 1; a <= K; a++)
    {
        for (long long b = 1; b <= K / a; b++)
        {
            long long c = K / a / b;
            ans += c;
        }
    }
    cout << ans << endl;
    return 0;
}