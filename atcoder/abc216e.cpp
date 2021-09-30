#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<long long> A(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    long long left = -1;
    long long right = 2000000000;

    while (left + 1 < right)
    {
        long long mid = (left + right) / 2;
        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (mid < A[i])
                sum += A[i] - mid;
        }
        if (K < sum)
            left = mid;
        else
            right = mid;
    }
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (right <= A[i])
        {
            ans += (A[i] + right + 1) * (A[i] - right) / 2;
            K -= A[i] - right;
        }
    }
    ans += K * right;
    cout << ans << endl;
    return 0;
}