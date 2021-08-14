#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int m = max(a, max(b, c));
    cout << (m - a) + (m - b) + (m - c) << endl;
    return 0;
}