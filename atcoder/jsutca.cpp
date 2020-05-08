#include <bits/stdc++.h>
using namespace std;

int main()
{
    int S, L, R;
    cin >> S >> L >> R;
    if (S < L)
        cout << L << endl;
    else if (L <= S && S <= R)
        cout << S << endl;
    else
        cout << R << endl;
    return 0;
}