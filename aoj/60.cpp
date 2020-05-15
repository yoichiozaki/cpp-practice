#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c1, c2, c3;
    while (cin >> c1 >> c2 >> c3)
    {
        int j = 0;
        for (int i = 1; i <= 10; i++)
        {
            if (i == c1 || i == c2 || i == c3)
                continue;
            if (c1 + c2 + i <= 20)
                j++;
        }
        if (7 < 2 * j)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}