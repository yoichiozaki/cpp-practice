#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> a(N);
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        a[i] = make_pair(x, i + 1);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
            cout << a[i].second << endl;
        else
            cout << a[i].second << " ";
    }
    return 0;
}