#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long X, Y, A, B;
    cin >> X >> Y >> A >> B;
    long long ans = 0;
    while ((double)A * X <= 2e18 && A * X <= X + B && A * X < Y)
    {
        X *= A;
        ans++;
    }
    cout << ans + (Y - 1 - X) / B << endl;
    return 0;
}