#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        A[i]--;
    }
    vector<int> B(N);
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    vector<int> C(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> C[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += B[A[i]];
        if (0 < i && A[i] == A[i - 1] + 1)
        {
            ans += C[A[i - 1]];
        }
    }
    cout << ans << endl;
    return 0;
}