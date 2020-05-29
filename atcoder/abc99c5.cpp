#include <iostream>
#include <queue>
using namespace std;

// よく愛用しています
template <class T>
bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

const int MAX_N = 110000;
int dp[MAX_N]; // dp[i] が i についての答え

int main()
{
    int N;
    cin >> N;

    // 初期化
    for (int i = 0; i < MAX_N; ++i)
        dp[i] = N; // INF
    dp[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push(make_pair(0, 0));

    // Dijkstra 法
    while (!que.empty())
    {
        int cur = que.top().first; // 現在の距離
        int v = que.top().second;  // 現在のノード
        que.pop();

        // Dijkstra 法でよくやる枝刈り
        if (cur > dp[v])
            continue;

        for (int pow6 = 1; v + pow6 <= N; pow6 *= 6)
        {
            int nv = v + pow6; // 遷移先
            if (chmin(dp[nv], dp[v] + 1))
                que.push(make_pair(dp[nv], nv));
        }
        for (int pow9 = 1; v + pow9 <= N; pow9 *= 9)
        {
            int nv = v + pow9; // 遷移先
            if (chmin(dp[nv], dp[v] + 1))
                que.push(make_pair(dp[nv], nv));
        }
    }

    cout << dp[N] << endl;
}