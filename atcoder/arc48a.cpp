#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long A, B;
    cin >> A >> B;
    long long ans = 0;
    if (A * B < 0)
    {
        ans = B - A - 1;
    }
    else
    {
        ans = B - A;
    }
    cout << ans << endl;
    return 0;
}