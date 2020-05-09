#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    for (int i = 0; i < m; i++)
        cin >> l[i] >> r[i];
    int lmax = *max_element(l.begin(), l.end());
    int rmin = *min_element(r.begin(), r.end());
    if (lmax <= rmin)
        cout << rmin - lmax + 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}