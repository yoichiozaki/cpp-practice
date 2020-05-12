#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a, b, c;
    char comma;
    int x = 0, y = 0;
    while (cin >> a >> comma >> b >> comma >> c)
    {
        if (a * a + b * b == c * c)
            x++;
        if (a == b)
            y++;
    }
    cout << x << endl;
    cout << y << endl;
    return 0;
}