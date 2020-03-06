#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 4000000;

ll n;
ll sum;
bitset<M + 5> v;

int main()
{
    scanf("%lld", &n);
    v[0] = true;
    while(n--)
    {
        ll t;
        scanf("%lld", &t);
        sum += t;
        v |= (v << t);
    }
    for(ll i = (sum + 1) / 2; i <= sum; i++)
    {
        if(v[i])
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}