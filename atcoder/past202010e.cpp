#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    string T = S;

    sort(S.begin(), S.end());

    do
    {
        if (S != T && S != string(T.rbegin(), T.rend()))
        {
            cout << S << endl;
            return 0;
        }
    } while (next_permutation(S.begin(), S.end()));

    cout << "None" << endl;
    return 0;
}