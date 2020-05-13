#include <bits/stdc++.h>
using namespace std;

int main()
{
    int u, n;
    char comma;
    int S = 0, U = 0, cnt = 0;
    ;
    while (cin >> u >> comma >> n)
    {
        cnt++;
        S += u * n;
        U += n;
    }
    cout << S << endl;
    cout << round(double(U) / double(cnt)) << endl;
    return 0;
}