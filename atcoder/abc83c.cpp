#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long X, Y;
    cin >> X >> Y;
    long long cnt = 1LL;
    while (X <= Y)
    {
        X *= 2LL;
        if (X > Y)
            break;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}