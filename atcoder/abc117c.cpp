#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    for (int i = 0; i < m; i++)
        cin >> x.at(i);
    sort(x.begin(), x.end());
    vector<int> d(m - 1);
    for (int i = 0; i < m - 1; i++)
        d.at(i) = x.at(i + 1) - x.at(i);
    sort(d.begin(), d.end(), greater<int>());
    for (int i = 0; i < n - 1 && i < m - 1; i++)
        d.at(i) = 0;
    int s = 0;
    for (int i = 0; i < m - 1; i++)
        s += d.at(i);
    cout << s << endl;
}
