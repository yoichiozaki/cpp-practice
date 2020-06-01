#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a;
    double b;
    cin >> a >> b;
    long long ib = b * 100 + 0.5;
    a *= ib;
    a /= 100;
    cout << (long long)a << endl;
    return 0;
}