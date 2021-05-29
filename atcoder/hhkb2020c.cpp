#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<bool> t(210000, false);
    int at = 0;
    for (int i = 0; i < N; i++)
    {
        int q;
        cin >> q;
        t[q] = true;
        while (t[at])
            at++;
        cout << at << endl;
    }
    return 0;
}