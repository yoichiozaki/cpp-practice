#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << max(2 * a - 1, max(a + b, 2 * b - 1)) << endl;
    return 0;
}