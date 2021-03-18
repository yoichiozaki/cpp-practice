#include <bits/stdc++.h>
using namespace std;

int main()
{
    string sA, sB;
    cin >> sA >> sB;
    int nA = 0, nB = 0;
    for (auto s : sA)
    {
        nA += int(s - '0');
    }
    for (auto s : sB)
    {
        nB += int(s - '0');
    }
    cout << max(nA, nB) << endl;
}