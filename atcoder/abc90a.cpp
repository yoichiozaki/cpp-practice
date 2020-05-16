#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char c;
            cin >> c;
            if (i == j)
            {
                cout << c;
            }
        }
    }
    cout << endl;
    return 0;
}