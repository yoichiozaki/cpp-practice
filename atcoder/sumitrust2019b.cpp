#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        if (i * 108 / 100 == N)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    return 0;
}