#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;
    vector<long long> A(N + 1), B(N + 1);
    for (long long i = 1; i <= N; i++)
        cin >> A[i];
    for (long long i = 1; i <= N; i++)
        cin >> B[i];
    vector<bool> DPA(N + 1, false), DPB(N + 1, false);
    DPA[1] = true;
    DPB[1] = true;
    for (long long i = 2; i <= N; i++)
    {
        if (DPA[i - 1])
        {
            if (abs(A[i - 1] - A[i]) <= K)
                DPA[i] = true;
            if (abs(A[i - 1] - B[i]) <= K)
                DPB[i] = true;
        }
        if (DPB[i - 1])
        {
            if (abs(B[i - 1] - A[i]) <= K)
                DPA[i] = true;
            if (abs(B[i - 1] - B[i]) <= K)
                DPB[i] = true;
        }
    }
    if (DPA[N] || DPB[N])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}