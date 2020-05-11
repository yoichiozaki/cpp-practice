#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int freq[100] = {};
    while (cin >> n)
    {
        freq[n - 1]++;
    }
    int m = 0;
    for (int i = 0; i < 100; i++)
        m = max(m, freq[i]);
    for (int i = 0; i < 100; i++)
    {
        if (freq[i] == m)
            cout << i + 1 << endl;
    }
    return 0;
}