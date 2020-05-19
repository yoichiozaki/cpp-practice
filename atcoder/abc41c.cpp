#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int N;
    cin >> N;
    vector<pair<ll, int>> a(N);
    for (int i = 0; i < N; i++)
    {
        ll ai;
        cin >> ai;
        a[i] = make_pair(ai, i + 1);
    }
    sort(a.rbegin(), a.rend());
    for (auto item : a)
    {
        cout << item.second << endl;
    }
    return 0;
}