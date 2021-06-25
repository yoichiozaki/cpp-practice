#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    // 累積和を用意しておく
    long long N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (long long i = 0; i < N; i++)
        cin >> A[i];
    vector<long long> cumulative_sum;
    cumulative_sum.push_back(A[0]);
    for (long long i = 1; i < N; i++)
    {
        cumulative_sum[i] = cumulative_sum[i - 1] + A[i];
    }
    for (long long i = K; i <= N; i++)
        cout << cumulative_sum[i] - cumulative_sum[i - K] << endl;
    return 0;
}