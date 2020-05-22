#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int ans = 0;
    for (int i = 1; i < N; i++)
    {
        if (A[i] < A[i - 1] + T)
            ans += A[i] - A[i - 1];
        else
            ans += T;
    }
    ans += T;
    cout << ans << endl;
    return 0;
}
