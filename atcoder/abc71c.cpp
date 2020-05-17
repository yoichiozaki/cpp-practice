#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int N;
    cin >> N;
    map<ll, int> mp;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        if (mp.count(a))
            mp[a]++;
        else
            mp[a] = 1;
        A[i] = a;
    }
    sort(A.begin(), A.end(), greater<ll>());
    ll ans;
    ll h = 0;
    ll w = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (mp[A[i]] < 2)
            continue;
        else if (mp[A[i]] >= 4)
        {
            h = w = A[i];
            cout << h * w << endl;
            return 0;
        }
        else
        {
            h = A[i];
            break;
        }
    }

    for (int i = 0; i < A.size(); i++)
    {
        if (mp[A[i]] < 2 || A[i] == h)
            continue;
        else
        {
            w = A[i];
            break;
        }
    }

    cout << h * w << endl;
}