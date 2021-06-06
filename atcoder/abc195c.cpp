#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long int ans = 0LL;
    if (1000LL <= N)
        ans += N - 999LL;
    if (1000000LL <= N)
        ans += N - 999999LL;
    if (1000000000LL <= N)
        ans += N - 999999999LL;
    if (1000000000000LL <= N)
        ans += N - 999999999999LL;
    if (1000000000000000LL <= N)
        ans += N - 999999999999999LL;
    cout << ans << endl;
    return 0;
}