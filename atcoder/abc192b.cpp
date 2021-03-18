#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int N = S.length();
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0 && 'a' <= S[i] && S[i] <= 'z')
        {
        }
        else if (i % 2 == 1 && 'A' <= S[i] && S[i] <= 'Z')
        {
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}