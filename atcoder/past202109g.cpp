#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;
    vector<long long> A(N), B(N), C(N);
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i] >> C[i];
    long long ng = 0, ok = 1LL << 60;
    while (ng + 1 < ok)
    {
        long long mid = (ng + ok) / 2;
        long long cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (mid < B[i])
                continue;
            long long num = (mid - B[i]) / C[i] + 1;
            cnt += min(A[i], num);
        }
        (K <= cnt ? ok : ng) = mid;
    }
    cout << ok << endl;
    return 0;
}