#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    vector<bool> a(x + 1);
    a[1] = true;
    for (int base = 2; base <= x; base++)
    {
        int v = base * base;
        while (v <= x)
        {
            a[v] = true;
            v *= base;
        }
    }
    for (int i = x; 1 <= i; i--)
        if (a[i])
        {
            cout << i << endl;
            return 0;
        }
    return 0;
}