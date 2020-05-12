#include <bits/stdc++.h>
using namespace std;

int INF = 1e9 + 5;

int main()
{
    int n;
    cin >> n;
    map<int, int> even, odd;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (i % 2 == 0)
        {
            even[num]++;
        }
        else
        {
            odd[num]++;
        }
    }
    int e = -1, e2 = -1, o = -1, o2 = -1;
    for (auto i : even)
    {
        if (i.second >= even[e])
        {
            e2 = e;
            e = i.first;
        }
        else if (i.second >= even[e2])
        {
            e2 = i.first;
        }
    }
    for (auto i : odd)
    {
        if (i.second >= odd[o])
        {
            o2 = o;
            o = i.first;
        }
        else if (i.second >= odd[o2])
        {
            o2 = i.first;
        }
    }
    if (e != o)
    {
        cout << n - even[e] - odd[o] << endl;
    }
    else
    {
        cout << min(n - even[e] - odd[o2], n - even[e2] - odd[o]) << endl;
    }
    return 0;
}