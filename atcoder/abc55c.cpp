#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, M;
    cin >> N >> M;
    long long ans = 0LL;
    if (N * 2LL <= M)
    {
        ans += N;
        M -= N * 2LL;
        ans += M / 4LL;
    }
    else
    {
        ans += M / 2LL;
    }
    cout << ans << endl;
    return 0;
}