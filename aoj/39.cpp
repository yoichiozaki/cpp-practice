#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        vector<int> v;
        for (int i = 0; i < str.size(); i++)
        {
            int x = 0;
            if (str[i] == 'I')
                x = 1;
            else if (str[i] == 'V')
                x = 5;
            else if (str[i] == 'X')
                x = 10;
            else if (str[i] == 'L')
                x = 50;
            else if (str[i] == 'C')
                x = 100;
            else if (str[i] == 'D')
                x = 500;
            else if (str[i] == 'M')
                x = 1000;

            v.push_back(x);
        }
        int ans = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] < v[i + 1])
                ans -= v[i]; // 大小関係が逆転していたら引き算
            else
                ans += v[i];
        }
        ans += v[v.size() - 1];
        cout << ans << endl;
    }
    return 0;
}