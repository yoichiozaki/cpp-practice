#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int zero = 0, one = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '0')
            zero++;
        else
            one++;
    }
    cout << min(zero, one) * 2 << endl;
    return 0;
}