#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    string s = string(b, '0' + a);
    string t = string(a, '0' + b);
    if (s < t)
        cout << s << endl;
    else
        cout << t << endl;
    return 0;
}