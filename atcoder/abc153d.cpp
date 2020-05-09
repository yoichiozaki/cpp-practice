#include <bits/stdc++.h>
using namespace std;

long long rec(long long H)
{
    if (H == 1LL)
        return 1;
    else
        return 2LL * rec(H / 2LL) + 1LL;
}

int main()
{
    long long H;
    cin >> H;
    cout << rec(H) << endl;
    return 0;
}