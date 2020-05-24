#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    int ans = 1001001;
    for (int i = -100; i <= 100; i++)
    {
        int cost = 0;
        for (int j = 0; j < N; j++)
            cost += (a[j] - i) * (a[j] - i);
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}