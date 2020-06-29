#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cnt = 0;
    string S, T;
    cin >> S >> T;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] != T[i])
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}