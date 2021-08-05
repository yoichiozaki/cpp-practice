#include <bits/stdc++.h>

using namespace std;

int main()
{
    double A, B, C;
    cin >> A >> B >> C;
    if (A <= (B * C))
    {
        cout << A / B << endl;
    }
    else
    {
        cout << C << endl;
    }
    return 0;
}