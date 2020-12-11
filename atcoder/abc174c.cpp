#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K;
    cin >> K;
    vector<int> a(K + 5, 0);
    a[1] = 7 % K;
    for (int i = 2; i <= K; i++)
    {
        a[i] = (a[i - 1] * 10 + 7) % K;
    }

    for (int i = 1; i <= K; i++)
    {
        if (a[i] == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}