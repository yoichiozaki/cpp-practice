#include <bits/stdc++.h>

using namespace std;

// N個の二人組の前列挙をどうやってやるか
// 一人目を残っている人の中で最小の人で固定する
// 深さ優先探索で全探索，再帰関数で実装すると簡単

int N;
int A[20][20];
vector<pair<int, int>> pairs; // N個の二人組．この配列を詰めていく．N個詰めきったら満足度を計算する
bool used[20];                // iさんがペア済みかを記録

int dfs()
{
    // basecase
    if (pairs.size() == N)
    {
        int ans = 0;
        for (auto p : pairs)
            ans ^= A[p.first][p.second];
        return ans;
    }

    // まだペアを作っていない最小の人を探す
    int lowest;
    for (int i = 1; i < 2 * N + 1; i++)
        if (!used[i])
        {
            lowest = i;
            break;
        }
    used[lowest] = true;

    int ans = 0;
    for (int i = 1; i < 2 * N + 1; i++)
    {
        if (!used[i])
        {
            pairs.push_back({lowest, i});
            used[i] = true;
            ans = max(ans, dfs());
            pairs.pop_back();
            used[i] = false;
        }
    }

    used[lowest] = false;
    return ans;
}

int main()
{
    cin >> N;
    for (int i = 1; i < 2 * N; i++)
    {
        for (int j = i + 1; j < 2 * N + 1; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << dfs() << endl;

    return 0;
}