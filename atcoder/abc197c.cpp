#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    int ans = 2000000000;

    // ビット全探索
    for (int i = 0; i < (1 << (N - 1)); i++)
    {
        int all_xored = 0;
        int all_ored = 0;
        for (int j = 0; j <= N; j++)
        {
            if (j < N)
            {
                all_ored |= A[j];
            }
            if (j == N || (i >> j & 1))
            {
                all_xored ^= all_ored;
                all_ored = 0;
            }
        }
        ans = min(ans, all_xored);
    }

    cout << ans << endl;
    return 0;
}