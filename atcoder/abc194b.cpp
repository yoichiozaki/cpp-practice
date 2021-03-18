#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i];
    int ans = 1000000000;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int cost = 0;
            if (i == j)
                cost = A[i] + B[j];
            else
                cost = max(A[i], B[j]);
            ans = min(ans, cost);
        }
    }
    cout << ans << endl;
    return 0;
}