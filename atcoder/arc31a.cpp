#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S, RS;
    cin >> S;
    RS = S;
    reverse(RS.begin(), RS.end());
    cout << (S == RS ? "YES" : "NO") << endl;
    return 0;
}