#include <bits/stdc++.h>
using namespace std;

// スタート・ゴール以外の頂点の次数が偶数かつスタート・ゴールの頂点の字数が奇数ならばOK

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        vector<int> d(105, 0);
        d[a]++, d[b]++;
        if (a == 0 && b == 0)
        {
            cout << "OK" << endl;
            continue;
        }
        while (cin >> a >> b, a || b)
        {
            d[a]++, d[b]++;
        }
        bool can = true;
        for (int i = 3; i < 105; i++)
            if (d[i] % 2 != 0)
                can = false;
        if (d[1] % 2 == 1 && d[2] % 2 == 1 && can)
            cout << "OK" << endl;
        else
            cout << "NG" << endl;
    }
    return 0;
}