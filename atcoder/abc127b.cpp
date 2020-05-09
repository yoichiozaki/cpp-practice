#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, D, x2000;
    cin >> r >> D >> x2000;
    vector<int> x(11);
    x[0] = x2000;
    for (int i = 1; i <= 10; i++)
    {
        x[i] = r * x[i - 1] - D;
    }
    for (int i = 1; i <= 10; i++)
        cout << x[i] << endl;
    return 0;
}