#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    long long K;
    cin >> S >> K;
    for (int i = 0; i < min((long long)S.size(), K); i++)
    {
        if ('2' <= S[i])
        {
            cout << S[i] << endl;
            return 0;
        }
    }
    cout << '1' << endl;
    return 0;
}