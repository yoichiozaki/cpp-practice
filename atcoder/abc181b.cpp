#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        long long a, b;
        cin >> a >> b;
        ans += (b + a) * (b - a + 1) / 2LL;
    }
    cout << ans << endl;
    return 0;
}