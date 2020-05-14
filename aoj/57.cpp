#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> a(10005, 0);
    a[1] = 2;
    for (int i = 2; i <= 10000; i++)
    {
        a[i] = a[i - 1] + i;
    }
    while (cin >> n)
    {
        cout << a[n] << endl;
    }
    return 0;
}