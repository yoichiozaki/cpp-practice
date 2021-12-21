#include <bits/stdc++.h>

using namespace std;

// 頂点IDの付替えを全部試す

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> G0(N, vector<bool>(N));
    vector<vector<bool>> G1(N, vector<bool>(N));

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        G0[a][b] = true;
        G0[b][a] = true;
    }

    for (int i = 0; i < M; i++)
    {
        int c, d;
        cin >> c >> d;
        c -= 1;
        d -= 1;
        G1[c][d] = G1[d][c] = true;
    }

    vector<int> relabel(N);
    for (int i = 0; i < N; i++)
        relabel[i] = i;

    do
    {
        bool is_same = true;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (G0[i][j] != G1[relabel[i]][relabel[j]])
                {
                    is_same = false;
                }
            }
        }
        if (is_same)
        {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(relabel.begin(), relabel.end()));
    cout << "No" << endl;

    return 0;
}