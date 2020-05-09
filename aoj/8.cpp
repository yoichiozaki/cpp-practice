#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> a(51, 0);
        for (int i = 0; i <= 9; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                for (int k = 0; k <= 9; k++)
                {
                    for (int l = 0; l <= 9; l++)
                    {
                        a[i + j + k + l]++;
                    }
                }
            }
        }
        cout << a[n] << endl;
    }
    return 0;
}