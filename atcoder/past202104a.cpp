#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    cout << (count(S.begin(), S.end(), '-') == 1 && S[3] == '-' ? "Yes" : "No") << endl;
    return 0;
}