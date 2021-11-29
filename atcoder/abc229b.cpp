#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    while (0 < a && 0 < b)
    {
        if (10 <= (a % 10) + (b % 10))
        {
            cout << "Hard" << endl;
            return 0;
        }
        a /= 10;
        b /= 10;
    }
    cout << "Easy" << endl;
    return 0;
}