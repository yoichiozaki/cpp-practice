#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p, q;
    while (cin >> p >> q)
    {
        vector<int> ans(100, 0), mod(100, 0);
        int pos = 0;
        p *= 10;
        while (pos < 100)
        {
            ans[pos] = p / q;
            mod[pos] = p;
            p %= q;
            p *= 10;
            pos++;
        }
        if (mod[99])
        {
            int ms = 0;
            int mt;
            for (;; ms++)
            {
                for (mt = ms + 1; mt < 100; mt++)
                {
                    if (mod[ms] == mod[mt])
                        break;
                }
                if (mt < 100)
                    break;
            }
            for (int i = 0; i < mt; i++)
                cout << ans[i];
            cout << endl;
            for (int i = 0; i < ms; i++)
                cout << " ";
            for (int i = 0; i < mt - ms; i++)
                cout << "^";
            cout << endl;
        }
        else
        {
            for (int i = 0; mod[i]; i++)
                cout << ans[i];
            cout << endl;
        }
    }
    return 0;
}