#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    if (a.size() < b.size())
        cout << b << endl;
    else
        cout << a << endl;
    return 0;
}