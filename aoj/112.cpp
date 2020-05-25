#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        vector<long long> t(n, 0LL);
        for (int i = 0; i < n; i++)
            cin >> t[i];
        sort(t.begin(), t.end());
        vector<long long> elapsed(n, 0LL);
        for (int i = 1; i < n; i++)
            elapsed[i] = t[i - 1] + elapsed[i - 1];
        cout << accumulate(elapsed.begin(), elapsed.end(), 0LL) << endl;
    }
    return 0;
}