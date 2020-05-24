#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<pair<int, int>> pq;
    int n, q;
    vector<int> mem;
    cin >> n >> q;
    mem.resize(n + 1, 0);
    pq.push(make_pair(0, -1));
    for (int i = 0, a, v; i < q; i++)
    {
        cin >> a >> v;
        mem[a] += v;
        pq.push(make_pair(mem[a], -a));
        while (!pq.empty())
        {
            int pf = pq.top().first, ps = pq.top().second;
            if (pf == mem[-ps])
            {
                cout << -ps << " " << pf << endl;
                break;
            }
            pq.pop();
        }
    }
}