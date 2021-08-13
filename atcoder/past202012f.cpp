#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> comb(M, vector<int>(3, 0));
    vector<int> ng_mask(M, 0);
    for (int i = 0; i < M; i++)
    {
        cin >> comb[i][0] >> comb[i][1] >> comb[i][2];
        comb[i][0] -= 1;
        comb[i][1] -= 1;
        comb[i][2] -= 1;
        ng_mask[i] |= 1 << comb[i][0];
        ng_mask[i] |= 1 << comb[i][1];
        ng_mask[i] |= 1 << comb[i][2];
    }

    int ans = 0;
    for (int bit = 0; bit < 1 << N; bit++)
    {
        vector<bool> check(N);
        bool ok = true;
        for (int i = 0; i < M; i++)
        {
            int x = bit & ng_mask[i];
            if (__builtin_popcount(x) == 2)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (!(bit & (1 << comb[i][j])))
                    {
                        check[comb[i][j]] = true;
                    }
                }
            }
            if (__builtin_popcount(x) == 3)
                ok = false;
        }
        if (ok)
        {
            int cnt = 0;
            for (int i = 0; i < N; i++)
            {
                if (check[i])
                    cnt++;
                ans = max(ans, cnt);
            }
        }
    }

    cout << ans << endl;
    return 0;
}