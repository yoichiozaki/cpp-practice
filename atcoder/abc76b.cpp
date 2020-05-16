#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int ans = 1001001;
    for (int bit = 0; bit < (1 << N); bit++)
    {
        int tmp = 1;
        for (int i = 0; i < N; i++)
        {
            if (bit & (1 << i))
                tmp += K;
            else
                tmp *= 2;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}