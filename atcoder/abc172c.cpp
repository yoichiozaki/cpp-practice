#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    long long K;
    cin >> N >> M >> K;
    vector<long long> A(N, 0LL), B(M, 0LL);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < M; i++)
        cin >> B[i];
    vector<long long> a = {0}, b = {0};
    for (int i = 0; i < N; i++)
        a.push_back(a[i] + A[i]);
    for (int i = 0; i < M; i++)
        b.push_back(b[i] + B[i]);
    int ans = 0, j = M;
    for (int i = 0; i <= N; i++)
    {
        if (K < a[i])
            break;
        while (K - a[i] < b[j])
            j--;
        ans = max(ans, i + j);
    }
    cout << ans << endl;
    return 0;
}