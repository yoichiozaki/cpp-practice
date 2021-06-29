#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 操作の順番が結果に影響しない
    // x，yはNより大きくならない
    // -> 全探索

    int N;
    string S;
    cin >> N >> S;

    int minimum = 1000000000;

    int x = -1, y = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            string T = S;
            for (int k = 0; k < i; k++)
            {
                for (int l = 1; l < N; l++)
                {
                    if (T[l] == '#')
                    {
                        T[l - 1] = '#';
                    }
                }
            }
            for (int k = 0; k < j; k++)
            {
                for (int l = N - 1; 0 < l; l--)
                {
                    if (T[l - 1] == '#')
                    {
                        T[l] = '#';
                    }
                }
            }

            bool ok = true;
            for (auto c : T)
            {
                if (c != '#')
                    ok = false;
            }

            if (ok && i + j < minimum)
            {
                minimum = i + j;
                x = i;
                y = j;
            }
        }
    }

    cout << x << " " << y << endl;
    return 0;
}