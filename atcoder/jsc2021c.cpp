#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    for (int c = B;; c--)
    {
        if ((A + c - 1) / c < B / c)
        {
            cout << c << endl;
            return 0;
        }
    }
    return 0;
}