#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, Q;
    cin >> N >> Q;
    vector<long long> A(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    vector<long long> num_candidates(N, 0);
    for (long long i = 0; i < N; i++)
    {
        num_candidates[i] = A[i] - (i + 1);
    }
    for (int q = 0; q < Q; q++)
    {
        long long K;
        cin >> K;
        int idx = lower_bound(num_candidates.begin(), num_candidates.end(), K) - num_candidates.begin();
        if (idx == N)
        {
            cout << A[N - 1] + (K - num_candidates[N - 1]) << endl;
        }
        else
        {
            cout << A[idx] - (num_candidates[idx] - K + 1) << endl;
        }
    }
    return 0;
}