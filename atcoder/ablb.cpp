#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b < c || d < a)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}