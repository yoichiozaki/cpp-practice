#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N), B(N), C(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    long long a_max = A[0];
    C[0] = A[0] * B[0];
    for (int i = 1; i < N; i++)
    {
        a_max = max(a_max, A[i]);
        C[i] = max(C[i - 1], a_max * B[i]);
    }
    for (int i = 0; i < N; i++)
    {
        cout << C[i] << endl;
    }
    return 0;
}