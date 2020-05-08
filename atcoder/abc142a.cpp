#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << fixed << setprecision(10);
    int odd = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
            odd++;
    }
    cout << float(odd) / float(n) << endl;
    return 0;
}