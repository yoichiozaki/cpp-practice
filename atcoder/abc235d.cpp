#include <bits/stdc++.h>

using namespace std;

// 整数iから操作によって整数jに変化させることができることを有向グラフで表現すると
// パラメタaに対して1を根とするグラフがかける．このグラフ上のBFSを実行すれば良い
// 整数Nを含む大きすぎないグラフを考える必要があるが，整数Nに至るまでの系列には
// 操作の内容からしてNの桁数ぐらいの数しか出てこないのでNの桁数+1桁の整数を頂点にして考えれば十分

int main()
{
    long long a, N;
    cin >> a >> N;

    long long maxv = 1;
    while (maxv <= N)
        maxv *= 10;

    vector<long long> dist(maxv, -1);
    dist[1] = 0;

    queue<long long> Q;
    Q.push(1);

    while (!Q.empty())
    {
        long long w = Q.front();
        Q.pop();

        long long candidate;

        candidate = a * w;
        if (candidate < maxv && dist[candidate] == -1)
        {
            dist[candidate] = dist[w] + 1;
            Q.push(candidate);
        }

        if (10 <= w && w % 10 != 0)
        {
            candidate = w % 10;
            for (int i = 0; i < to_string(w).length() - 1; i++)
                candidate *= 10;
            candidate += w / 10;
            if (candidate < maxv && dist[candidate] == -1)
            {
                dist[candidate] = dist[w] + 1;
                Q.push(candidate);
            }
        }
    }

    cout << dist[N] << endl;
    return 0;
}