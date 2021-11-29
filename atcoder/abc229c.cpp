#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, W;
    cin >> N >> W;
    vector<pair<long long, long long>> cheese(N);
    for (int i = 0; i < N; i++)
    {
        long long A, B;
        cin >> A >> B;
        cheese[i] = make_pair(A, B);
    }
    sort(cheese.begin(), cheese.end());
    reverse(cheese.begin(), cheese.end());
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += cheese[i].first * min(W, cheese[i].second);
        W -= min(W, cheese[i].second);
    }
    cout << ans << endl;
    return 0;
}