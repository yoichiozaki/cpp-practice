#include <bits/stdc++.h>
using namespace std;

bool check(int n)
{
    for (int i = 0; i * i <= n; i++)
    {
        if (i * i == n)
            return true;
    }
    return false;
}

int main()
{
    string a, b;
    cin >> a >> b;
    int x = atoi((a + b).c_str());
    if (check(x))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}