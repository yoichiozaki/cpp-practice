#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<long long> c(N), p(N);
    for (int i = 0; i < N; i++)
        cin >> c[i];
    for (int i = 0; i < N; i++)
        cin >> p[i];
    vector<pair<long long, long long>> orders;
    for (int i = 0; i < N; i++)
        orders.push_back({p[i], c[i]});
    sort(orders.begin(), orders.end());
    set<int> chosen;
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        long long price = orders[i].first;
        long long color = orders[i].second;
        if (chosen.count(color))
            continue;
        ans += price;
        chosen.insert(color);
        if (chosen.size() == K)
        {
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}