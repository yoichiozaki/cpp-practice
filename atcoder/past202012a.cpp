#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    string ans = "draw";
    if (S[0] == S[1] && S[1] == S[2])
        ans = S[0];
    if (S[1] == S[2] && S[2] == S[3])
        ans = S[1];
    if (S[2] == S[3] && S[3] == S[4])
        ans = S[2];
    cout << ans << endl;
    return 0;
}