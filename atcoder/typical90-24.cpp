#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;
    vector<long long> A(N, 0), B(N, 0);
    for (long long i = 0; i < N; i++)
        cin >> A[i];
    for (long long i = 0; i < N; i++)
        cin >> B[i];

    long long diff = 0;
    for (long long i = 0; i < N; i++)
        diff += abs(A[i] - B[i]);
    if (K < diff)
    {
        cout << "No" << endl;
        return 0;
    }
    if (diff % 2 != K % 2)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}