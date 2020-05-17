#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    vector<ll> even, odd;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        if (i % 2 == 0)
            odd.push_back(a);
        else
            even.push_back(a);
    }
    vector<ll> ans;
    if (n % 2 == 0)
    {
        for (int i = even.size() - 1; 0 <= i; i--)
        {
            ans.push_back(even[i]);
        }
        for (int i = 0; i < odd.size(); i++)
        {
            ans.push_back(odd[i]);
        }
    }
    else
    {
        for (int i = odd.size() - 1; 0 <= i; i--)
        {
            ans.push_back(odd[i]);
        }
        for (int i = 0; i < even.size(); i++)
        {
            ans.push_back(even[i]);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1)
        {
            cout << ans[i] << endl;
        }
        else
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}