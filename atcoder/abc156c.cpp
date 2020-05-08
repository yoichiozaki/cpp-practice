#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> X(N, 0);
    int maxn, minn;
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
    }
    sort(X.begin(), X.end());
    maxn = X[N - 1];
    minn = X[0];
    int ans = 10010010;
    for (int i = minn; i <= maxn; i++)
    {
        int tmp = 0;
        for (int j = 0; j < N; j++)
        {
            tmp += (i - X[j]) * (i - X[j]);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}