#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if ((a == b && b != c) || (a == c && c != b) || (c == b && a != b))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}