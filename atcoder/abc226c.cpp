#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> T(N);
    vector<int> K(N);
    vector<vector<int>> A(N, vector<int>());
    vector<bool> used(N, false);
    for (int i = 0; i < N; i++)
    {
        cin >> T[i] >> K[i];
        for (int j = 0; j < K[i]; j++)
        {
            int a;
            cin >> a;
            a--;
            A[i].push_back(a);
        }
    }

    used[N - 1] = true;
    long long ans = 0;
    for (int i = N - 1; 0 <= i; i--)
    {
        if (used[i])
        {
            ans += T[i];
            for (int j = 0; j < K[i]; j++)
            {
                used[A[i][j]] = true;
            }
        }
    }

    cout << ans << endl;
    return 0;
}