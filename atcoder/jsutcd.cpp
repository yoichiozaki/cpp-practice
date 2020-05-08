#include <bits/stdc++.h>
using namespace std;

long long GCD(long long x, long long y)
{
    if (y == 0)
        return x;
    else
        return GCD(y, x % y);
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 1; i < N; ++i)
        A[i] = GCD(A[i - 1], A[i]);

    for (int _ = 0; _ < Q; ++_)
    {
        long long x;
        cin >> x;
        int left = -1, right = N;
        while (right - left > 1)
        {
            long long mid = (left + right) / 2;
            long long g = GCD(x, A[mid]);
            if (g == 1)
                right = mid;
            else
                left = mid;
        }
        if (right == N)
            cout << GCD(A.back(), x) << endl;
        else
            cout << right + 1 << endl;
    }
}