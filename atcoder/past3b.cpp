#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> table(N, vector<int>(0));
    // table[i] = [iさんが正解した問題番号の一覧]
    vector<int> board(M, N);
    // board[i] = N - 問題iを正解した人数
    for (int q = 0; q < Q; q++)
    {
        int typ;
        cin >> typ;
        if (typ == 1)
        {
            int n;
            cin >> n;
            n--;
            int ans = 0;
            for (auto x : table[n])
            {
                ans += board[x];
            }
            cout << ans << endl;
        }
        else
        {
            int n, m;
            cin >> n >> m;
            n--, m--;
            table[n].push_back(m);
            board[m]--;
        }
    }
    return 0;
}