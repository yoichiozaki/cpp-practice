#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<vector<int>> T(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> T[i][j];
        }
    }

    vector<int> idx;
    for (int i = 0; i < N; i++)
        idx.push_back(i);

    int ans = 0;
    do
    {
        int elapsed = 0;
        for (int i = 0; i < N; i++)
            elapsed += T[idx[i]][idx[(i + 1)] % N];
        if (elapsed == K)
            ans++;
    } while (next_permutation(idx.begin() + 1, idx.end()));

    cout << ans << endl;
    return 0;
}