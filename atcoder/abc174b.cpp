#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, D, X, Y, ret;
    cin >> N >> D;
    ret = 0LL;
    for (long long i = 0; i < N; i++)
    {
        cin >> X >> Y;
        if (X * X + Y * Y <= D * D)
            ret++;
    }
    cout << ret << endl;
    return 0;
}