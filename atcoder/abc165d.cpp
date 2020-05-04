#include <bits/stdc++.h>
using namespace std;

// floor(a/b) = (a-a%b)/b

int main()
{
    long long a, b, n;
    cin >> a >> b >> n;
    long long x = n;
    if (b - 1 <= n)
        x = b - 1;
    long long ans = a * x / b - a * (x / b);
    cout << ans << endl;
    return 0;
}