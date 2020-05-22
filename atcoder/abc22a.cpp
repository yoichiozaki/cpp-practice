#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, S, T;
    cin >> N >> S >> T;
    int W;
    cin >> W;
    vector<int> A(N);
    A[0] = W;
    for (int i = 1; i < N; i++)
    {
        int a;
        cin >> a;
        A[i] = A[i - 1] + a;
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (S <= A[i] && A[i] <= T)
            ans++;
    }
    cout << ans << endl;
    return 0;
}