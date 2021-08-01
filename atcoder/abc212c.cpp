#include <bits/stdc++.h>

using namespace std;
#define INF 1010000000

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N, 0);
    vector<int> B(M, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < M; i++)
        cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int n = 0;
    int m = 0;
    int ans = INF;

    while (n < N && m < M)
    {
        ans = min(ans, abs(A[n] - B[m]));
        if (A[n] > B[m])
            m++;
        else
            n++;
    }

    cout << ans << endl;
    return 0;
}