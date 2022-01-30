#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> R(n + 1);
    vector<int> C(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> R[i];
    for (int i = 1; i <= n; i++)
        cin >> C[i];
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int r, c;
        cin >> r >> c;
        if (R[r] + C[c] >= n + 1)
            cout << "#";
        else
            cout << ".";
    }
    cout << endl;
    return 0;
}