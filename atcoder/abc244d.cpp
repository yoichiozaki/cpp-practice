#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main()
{
    char a[3], b[3];
    rep(i, 3) cin >> a[i];
    rep(i, 3) cin >> b[i];
    vector<int> v(3, -1);
    rep(i, 3)
    {
        rep(j, 3)
        {
            if (a[i] == b[j])
            {
                v[j] = i;
            }
        }
    }
    vector<int> v1 = {0, 1, 2};
    vector<int> v2 = {2, 0, 1};
    vector<int> v3 = {1, 2, 0};
    if (v == v1 || v == v2 || v == v3)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
}