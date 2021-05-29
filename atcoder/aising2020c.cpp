#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> table(10010, 0);
    for (int x = 1; x <= 100; x++)
    {
        for (int y = 1; y <= 100; y++)
        {
            for (int z = 1; z <= 100; z++)
            {
                int f = x * x + y * y + z * z + x * y + y * z + z * x;
                if (f <= N)
                    table[f]++;
            }
        }
    }
    for (int i = 1; i <= N; i++)
        cout << table[i] << endl;
    return 0;
}