#include <bits/stdc++.h>
using namespace std;

int main()
{
    char C, c;
    cin >> C >> c;
    if (C - 'A' + 'a' == c)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}