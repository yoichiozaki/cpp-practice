#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }
    sort(L.begin(), L.end(), greater<int>());
    int m = 0;
    for (int i = 1; i < L.size(); i++)
        m += L[i];
    if (L[0] < m)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}