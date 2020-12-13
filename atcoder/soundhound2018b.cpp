#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int w;
    cin >> w;
    for (int i = 0; i * w < S.size(); i++)
        cout << S[i * w];
    cout << endl;
    return 0;
}