#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    bitset<100> follow[100];
    for (int q = 0; q < Q; q++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int a, b;
            cin >> a >> b;
            a -= 1;
            b -= 1;
            follow[a][b] = true;
        }
        else if (t == 2)
        {
            int a;
            cin >> a;
            a -= 1;
            for (int u = 0; u < N; u++)
            {
                if (follow[u][a])
                    follow[a][u] = true;
            }
        }
        else
        {
            int a;
            cin >> a;
            a -= 1;
            vector<int> followers;
            for (int x = 0; x < N; x++)
            {
                if (follow[a][x])
                    followers.push_back(x);
            }
            for (auto x : followers)
                follow[a] |= follow[x];
        }
    }

    for (int i = 0; i < N; i++)
        follow[i][i] = false;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (follow[i][j])
                cout << "Y";
            else
                cout << "N";
        }
        cout << endl;
    }

    return 0;
}