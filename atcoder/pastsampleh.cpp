#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    priority_queue<long long> pq;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        pq.push(a);
    }
    for (int i = 0; i < M; i++)
    {
        long long x = pq.top();
        pq.pop();
        pq.push(x / 2LL);
    }
    long long ans = 0LL;
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}