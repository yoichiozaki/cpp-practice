#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> x = {
    {1, 2, 1, 2, 1, 4, 1, 4},
    {1, 2, 1, 4, 1, 4, 1, 2},
    {1, 4, 1, 2, 1, 2, 1, 4},
    {1, 4, 1, 4, 1, 2, 1, 2},
    {2, 1, 2, 1, 4, 1, 4, 1},
    {2, 1, 4, 1, 4, 1, 2, 1},
    {4, 1, 2, 1, 2, 1, 4, 1},
    {4, 1, 4, 1, 2, 1, 2, 1},
};

int main()
{
    int p0, p1, p2, p3, p4, p5, p6, p7;
    while (cin >> p0 >> p1 >> p2 >> p3 >> p4 >> p5 >> p6 >> p7)
    {
        vector<int> p = {p0, p1, p2, p3, p4, p5, p6, p7};
        int remain = 1001001;
        int ans = -1;
        for (int i = 0; i < x.size(); i++)
        {
            int tmp = 0;
            for (int j = 0; j < 8; j++)
            {
                tmp += max(p[j] - x[i][j], 0);
            }
            if (tmp < remain)
            {
                ans = i;
                remain = tmp;
            }
        }
        for (int i = 0; i < 8; i++)
        {
            if (i == 7)
                cout << x[ans][i] << endl;
            else
                cout << x[ans][i] << " ";
        }
    }
    return 0;
}