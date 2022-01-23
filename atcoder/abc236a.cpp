#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    int a, b;
    cin >> a >> b;
    a--, b--;
    char tmp = S[a];
    S[a] = S[b];
    S[b] = tmp;
    cout << S << endl;
    return 0;
}