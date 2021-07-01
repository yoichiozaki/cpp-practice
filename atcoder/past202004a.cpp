#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S, T;
    int s, t;
    cin >> S >> T;
    if (S[0] == 'B')
        s = -(S[1] - '0') + 1;
    else
        s = S[0] - '0';

    if (T[0] == 'B')
        t = -(T[1] - '0') + 1;
    else
        t = T[0] - '0';

    cout << abs(t - s) << endl;
    return 0;
}