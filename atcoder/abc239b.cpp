#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long X;
    cin >> X;
    if (X < 0 and X % 10 != 0)
        cout << X / 10 - 1 << endl;
    else
        cout << X / 10 << endl;
    return 0;
}