#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<bool> ng(301);
    for (int i = 0; i < 3; ++i)
    {
        int a;
        cin >> a;
        ng[a] = true;
    }

    bool ok = true;
    if (ng[N])
    {
        ok = false;
    }
    else
        for (int i = 0; i < 100 && N > 0; ++i)
        {
            if (N >= 3 && !ng[N - 3])
            {
                N -= 3;
            }
            else if (N >= 2 && !ng[N - 2])
            {
                N -= 2;
            }
            else if (!ng[N - 1])
            {
                N -= 1;
            }
            else
            {
                ok = false;
                break;
            }
        }
    if (N > 0)
    {
        ok = false;
    }

    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}