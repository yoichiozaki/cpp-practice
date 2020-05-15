#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int x = b - a;
    cout << x * (x + 1) / 2 - b << endl;
    return 0;
}