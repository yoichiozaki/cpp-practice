#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        vector<int> v10(10, 0);
        for (int i = 0; i < 10; i++)
            v10[i] = s[i] - '0';
        for (int j = 1; j < 10; j++)
        {
            for (int i = 0; i < 10 - j; i++)
            {
                v10[i] = (v10[i] + v10[i + 1]) % 10;
            }
        }
        cout << v10[0] << endl;
    }
    return 0;
}