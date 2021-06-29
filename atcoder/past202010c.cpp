#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> field(N);
    for (int i = 0; i < N; i++)
        cin >> field[i];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int cnt = 0;
            for (int dx = -1; dx < 2; dx++)
            {
                for (int dy = -1; dy < 2; dy++)
                {
                    if (0 <= i + dx && i + dx < N && 0 <= j + dy && j + dy < M && field[i + dx][j + dy] == '#')
                        cnt++;
                }
            }
            cout << cnt;
        }
        cout << endl;
    }
    return 0;
}