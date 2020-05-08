#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A, B, X;

bool is_ok(long long N)
{
    ll d = ll(to_string(N).size());
    if (A * N + B * d <= X)
    {
        return true;
    }
    return false;
}

ll binary_search()
{
    ll ok = -1;
    ll ng = 1000000000;
    while (1 < abs(ok - ng))
    {
        ll mid = (ok + ng) / 2;
        if (is_ok(mid))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main()
{
    cin >> A >> B >> X;
    cout << binary_search() << endl;
    return 0;
}