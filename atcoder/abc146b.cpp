#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++)
    {
        if ('Z' < S[i] + N)
        {
            cout << char((S[i] + N) - 'Z' - 1 + 'A');
        }
        else
            cout << char(S[i] + N);
    }
    cout << endl;
    return 0;
}