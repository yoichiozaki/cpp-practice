#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    auto p = find(S.begin(), S.end(), 'o');
    if (p == S.end())
        cout << "none" << endl;
    else
        cout << (p - S.begin() + 3) / 4 << endl;
    return 0;
}