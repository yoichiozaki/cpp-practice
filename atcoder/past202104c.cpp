#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++)
    {
        int K;
        cin >> K;
        A[i].resize(K);
        for (int k = 0; k < K; k++)
        {
            cin >> A[i][k];
        }
    }
    int P, Q;
    cin >> P >> Q;
    vector<int> B(P);
    for (int i = 0; i < P; i++)
        cin >> B[i];
    int ans = 0;
    for (auto i : A)
    {
        int cur = 0;
        for (auto j : i)
        {
            cur += count(B.begin(), B.end(), j);
        }
        ans += (Q <= cur);
    }
    cout << ans << endl;
    return 0;
}