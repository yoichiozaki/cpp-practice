#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++)
        {
            int rsum = 0;
            for (int j = 0; j < n; j++)
            {
                cin >> table[i][j];
                rsum += table[i][j];
            }
            table[i][n] = rsum;
        }
        for (int i = 0; i < n; i++)
        {
            int csum = 0;
            for (int j = 0; j < n; j++)
            {
                csum += table[j][i];
            }
            table[n][i] = csum;
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += table[n][i];
        table[n][n] = sum;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << right << setw(5) << setfill(' ') << table[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}