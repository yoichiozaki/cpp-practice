#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    int g = __gcd(a, b);
    int l = a * b / g;
    l *= (n + l - 1) / l;
    cout << l << endl;
    return 0;
}