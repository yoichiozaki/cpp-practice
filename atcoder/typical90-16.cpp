#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, A, B, C;
    cin >> N >> A >> B >> C;

    long long ret = (1LL << 30);
    for (int i = 0; i <= 9999; i++)
    {
        for (int j = 0; j <= 9999 - i; j++)
        {
            long long remain = N - 1LL * i * A - 1LL * j * B;
            long long k = 1LL * i + 1LL * j + remain / C;
            if (remain % C != 0 || remain < 0 || 9999LL < k)
                continue;
            ret = min(ret, k);
        }
    }
    cout << ret << endl;
    return 0;
}