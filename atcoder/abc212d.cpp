#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long P, Q;
    cin >> Q;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    long long sum = 0;
    for (long long _ = 0; _ < Q; _++)
    {
        cin >> P;
        if (P == 1)
        {
            long long x;
            cin >> x;
            pq.push(x - sum);
        }
        else if (P == 2)
        {
            long long x;
            cin >> x;
            sum += x;
        }
        else if (P == 3)
        {
            long long x;
            x = pq.top();
            cout << x + sum << endl;
            pq.pop();
        }
    }
    return 0;
}