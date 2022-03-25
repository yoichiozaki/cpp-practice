#include <bits/stdc++.h>

using namespace std;

bool sign(string S)
{
    return S == "R G B" || S == "G B R" || S == "B R G";
}
int main()
{
    string S, T;
    cin >> S >> T;
    if (sign(S) == sign(T))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}