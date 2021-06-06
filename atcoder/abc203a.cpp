#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && a != c)
        cout << c << endl;
    else if (b == c && b != a)
        cout << a << endl;
    else if (c == a && c != b)
        cout << b << endl;
    else if (a == b && b == c)
        cout << a << endl;
    else
        cout << 0 << endl;
    return 0;
}