#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> X(N);
    for (int i = 0; i < N; i++)
        cin >> X[i];
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += min(X[i], K - X[i]);
    }
    cout << ans * 2 << endl;
    return 0;
}