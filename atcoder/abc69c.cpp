#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int dev4 = 0;
    int odd = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
        if (a.at(i) % 2 != 0)
            odd++;
        if (a.at(i) % 4 == 0)
            dev4++;
    }
    if (odd + dev4 == n && odd > dev4 + 1)
        cout << "No" << endl;
    else if (odd + dev4 != n && odd > dev4)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}