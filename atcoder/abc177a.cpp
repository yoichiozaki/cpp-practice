#include <bits/stdc++.h>
using namespace std;

int main()
{
    int D, T, S;
    cin >> D >> T >> S;
    if (D <= S * T)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}