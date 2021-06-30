#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> solved(N, vector<int>(M, 0));
    vector<int> score(M, 0);

    while (Q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int n;
            cin >> n;
            n--;
            int ans = 0;
            for (int i = 0; i < M; i++)
            {
                if (solved[n][i])
                    ans += N - score[i];
            }
            cout << ans << endl;
        }
        else
        {
            int n, m;
            cin >> n >> m;
            n--;
            m--;
            solved[n][m] += 1;
            score[m] += 1;
        }
    }
    return 0;
}