#include <bits/stdc++.h>
using namespace std;

int main()
{
    char S, T;
    cin >> S >> T;
    if (S == 'Y')
        cout << char(T - 'a' + 'A') << endl;
    else
        cout << T << endl;
    return 0;
}