#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int ans = 0;
    for (int n = 1; n <= N; n++)
    {
        for (int k = 1; k <= K; k++)
        {
            ans += 100 * n + k;
        }
    }
    cout << ans << endl;
    return 0;
}