#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a(10);

bool rec(int idx, vector<int> &b, vector<int> &c)
{
    if (idx == 10)
    {
        for (int i = 0; i + 1 < b.size(); i++)
        {
            if (b[i] > b[i + 1])
                return false;
        }
        for (int i = 0; i + 1 < c.size(); i++)
        {
            if (c[i] > c[i + 1])
                return false;
        }
        return true;
    }

    b.push_back(a[idx]);
    if (rec(idx + 1, b, c))
        return true;
    b.pop_back();

    c.push_back(a[idx]);
    if (rec(idx + 1, b, c))
        return true;
    c.pop_back();

    return false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
            cin >> a[j];
        vector<int> b, c;
        if (rec(0, b, c))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}