#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string A, B, C;
    cin >> A >> B >> C;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if ((A[i] != B[i] && B[i] == C[i]) || (A[i] == C[i] && B[i] != C[i]) || (C[i] != A[i] && B[i] == A[i]))
        {
            ans += 1;
        }
        else if (A[i] != B[i] && B[i] != C[i] && C[i] != A[i])
        {
            ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}