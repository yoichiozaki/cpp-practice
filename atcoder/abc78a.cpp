#include <bits/stdc++.h>
using namespace std;

long long dp[90];

int main()
{
    char X, Y;
    cin >> X >> Y;
    if (X < Y)
        cout << "<" << endl;
    else if (X == Y)
        cout << "=" << endl;
    else
        cout << '>' << endl;
    return 0;
}