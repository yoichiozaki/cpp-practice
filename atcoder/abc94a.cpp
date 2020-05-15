#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, x;
    cin >> a >> b >> x;
    if (a <= x && x <= a + b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}