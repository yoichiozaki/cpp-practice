#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> B(N - 1);
    for (int i = 0; i < N - 1; i++)
        cin >> B[i];
    vector<int> A(N, 0);
    A[0] = B[0];
    for (int i = 0; i < N - 2; i++)
    {
        A[i + 1] = min(B[i], B[i + 1]);
    }
    A[N - 1] = B[N - 2];
    int ans = 0;
    for (int i = 0; i < N; i++)
        ans += A[i];
    cout << ans << endl;
    return 0;
}