#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<string> table(N);
    for (int i = 0; i < N; i++)
        cin >> table[i];

    vector<vector<vector<int>>> counter(N + 1, vector<vector<int>>(M + 1, vector<int>(10, 0)));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int digit = table[i][j] - '0';
            counter[i + 1][j + 1][digit]++;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            for (int digit = 0; digit < 10; digit++)
            {
                counter[i][j][digit] += counter[i][j - 1][digit] + counter[i - 1][j][digit] - counter[i - 1][j - 1][digit];
            }
        }
    }

    int x = min(N, M);
    while (x)
    {
        for (int i = x; i <= N; i++)
        {
            for (int j = x; j <= M; j++)
            {
                for (int digit = 0; digit < 10; digit++)
                {
                    if (x * x - K <= counter[i][j][digit] - counter[i][j - x][digit] - counter[i - x][j][digit] + counter[i - x][j - x][digit])
                    {
                        cout << x << endl;
                        return 0;
                    }
                }
            }
        }
        x -= 1;
    }
    return 0;
}