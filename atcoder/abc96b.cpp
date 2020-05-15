#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int k;
    cin >> k;
    cout << a + b + c + max({a, b, c}) * ((1 << k) - 1) << endl;
    return 0;
}