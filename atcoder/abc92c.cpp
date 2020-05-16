#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N + 2);
    A[0] = A[N + 1] = 0;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    long long sum = 0;
    for (int i = 1; i <= N + 1; i++)
        sum += abs(A[i] - A[i - 1]);
    for (int i = 1; i <= N; i++)
    {
        cout << sum - abs(A[i + 1] - A[i]) - abs(A[i] - A[i - 1]) + abs(A[i + 1] - A[i - 1]) << endl;
    }
    return 0;
}