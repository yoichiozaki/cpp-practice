#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 1;; i++)
    {
        if (N < i * i)
        {
            cout << (i - 1) * (i - 1) << endl;
            return 0;
        }
    }
    return 0;
}