#include <bits/stdc++.h>
using namespace std;

int main()
{
    double v;
    while (cin >> v)
    {
        cout << ceil(v * v / (10.0 * 9.8) + 1) << endl;
    }
    return 0;
}