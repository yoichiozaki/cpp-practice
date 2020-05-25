#include <bits/stdc++.h>
using namespace std;

// 「チケットが手元にある限り，その時点で一番高価な品物に適用する」を繰り返すのが最適

int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pq.push(a);
    }
    for (int i = 0; i < m; i++)
    {
        int item = pq.top();
        pq.pop();
        pq.push(item / 2);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += pq.top(), pq.pop();
    cout << ans << endl;
    return 0;
}
