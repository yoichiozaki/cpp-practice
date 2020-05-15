#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> a(N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        int p;
        cin >> p;
        a[p] = 1;
    }
    int left = 0, right = 0;
    for (int i = X; 0 <= i; i--)
        left += a[i];
    for (int i = X; i < N + 1; i++)
        right += a[i];
    cout << min(left, right) << endl;
    return 0;
}