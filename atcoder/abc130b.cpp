#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    vector<int> L(N + 1);
    for (int i = 1; i < N + 1; i++)
        cin >> L[i];
    for (int i = 1; i < N + 1; i++)
        L[i] += L[i - 1];
    cout << distance(L.begin(), upper_bound(L.begin(), L.end(), X)) << endl;
    return 0;
}