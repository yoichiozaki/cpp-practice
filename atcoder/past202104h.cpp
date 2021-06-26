#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, M, K, Q;
    cin >> N >> M >> K >> Q;
    vector<long long> A, B;
    A.push_back(0);
    B.push_back(0);
    for (int i = 0; i < N; i++)
    {
        long long P, T;
        cin >> P >> T;
        if (T == 0)
            A.push_back(P);
        else
            B.push_back(P);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (long long i = 1; i < A.size(); i++)
    {
        A[i] += A[i - 1];
    }
    for (long long i = 1; i < B.size(); i++)
    {
        B[i] += B[i - 1];
    }

    long long ans = 1LL << 60;
    for (long long i = 0; i < B.size(); i++)
    {
        long long j = M - i;
        if (0 <= j && j < A.size())
        {
            ans = min(ans, A[j] + B[i] + (i + K - 1) / K * Q);
        }
    }
    cout << ans << endl;
    return 0;
}