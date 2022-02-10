#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long H, W, C, Q;
    cin >> H >> W >> C >> Q;
    vector<tuple<long long, long long, long long>> query(Q);
    for (long long i = 0; i < Q; i++)
    {
        long long t, n, c;
        cin >> t >> n >> c;
        query[i] = make_tuple(t, n, c);
    }
    vector<long long> ans(C + 1, 0);
    set<long long> done1, done2;
    for (long long i = Q - 1; 0 <= i; i--)
    {
        long long t = get<0>(query[i]);
        long long n = get<1>(query[i]);
        long long c = get<2>(query[i]);
        if (t == 1 && done1.find(n) == done1.end())
        {
            done1.insert(n);
            ans[c] += W - done2.size();
        }
        if (t == 2 && done2.find(n) == done2.end())
        {
            done2.insert(n);
            ans[c] += H - done1.size();
        }
    }
    for (long long i = 1; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}