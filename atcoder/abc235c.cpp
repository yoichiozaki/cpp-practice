#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    map<int, vector<int>> table;
    for (int i = 0; i < N; i++)
    {
        if (table[A[i]].size() == 0)
        {
            vector<int> a;
            table[A[i]] = a;
        }
        table[A[i]].push_back(i + 1);
    }
    for (int i = 0; i < Q; i++)
    {
        int x, k;
        cin >> x >> k;
        if (k <= table[x].size())
            cout << table[x][k - 1] << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}