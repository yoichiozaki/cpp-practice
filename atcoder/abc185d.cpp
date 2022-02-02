#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++)
        cin >> A[i];
    sort(A.begin(), A.end());
    A.push_back(N + 1);

    int curr = 1;
    vector<int> B;
    for (int i = 0; i < M + 1; i++)
    {
        int width = A[i] - curr;
        if (width != 0)
            B.push_back(width);
        curr = A[i] + 1;
    }

    int k = INT_MAX / 2;
    for (int width : B)
        k = min(k, width);

    int ans = 0;
    for (int width : B)
        ans += (width + k - 1) / k;
    cout << ans << endl;
    return 0;
}