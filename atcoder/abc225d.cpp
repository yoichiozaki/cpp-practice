#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, Q;
    cin >> N >> Q;
    long long none = -1;

    vector<long long> front(N + 1, none);
    vector<long long> back(N + 1, none);

    for (long long _ = 0; _ < Q; _++)
    {
        long long C;
        cin >> C;
        if (C == 1)
        {
            long long x, y;
            cin >> x >> y;
            back[x] = y;
            front[y] = x;
        }
        else if (C == 2)
        {
            long long x, y;
            cin >> x >> y;
            back[x] = none;
            front[y] = none;
        }
        else
        {
            long long x;
            cin >> x;
            while (front[x] != none)
            {
                x = front[x];
            }
            vector<long long> ans;
            while (x != none)
            {
                ans.push_back(x);
                x = back[x];
            }
            cout << ans.size() << " ";
            for (long long i = 0; i < ans.size(); i++)
            {
                cout << ans[i];
                if (i == ans.size() - 1)
                    cout << endl;
                else
                    cout << " ";
            }
        }
    }
    return 0;
}