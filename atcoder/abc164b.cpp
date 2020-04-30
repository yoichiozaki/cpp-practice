#include <bits/stdc++.h>
using namespace std;

int f(int a, int hp)
{
    return (hp + a - 1) / a;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (f(b, c) <= f(d, a))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}