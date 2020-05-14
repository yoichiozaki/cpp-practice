#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        long long maxm = 0LL, minm = 0LL;
        long long f = 1LL;
        for (int j = 7; - 1 < j; j--)
        {
            minm += f * (s[j] - '0');
            f *= 10LL;
        }
        sort(s.rbegin(), s.rend());
        f = 1LL;
        for (int j = 7; - 1 < j; j--)
        {
            maxm += f * (s[j] - '0');
            f *= 10LL;
        }
        cout << maxm - minm << endl;
    }
    return 0;
}