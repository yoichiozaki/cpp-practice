#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, L, T, X;
    cin >> N >> L >> T >> X;
    vector<int> A(N, 0), B(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i];
    for (int i = 0; i < N; i++)
    {
        if (T < A[i] && L <= B[i])
        {
            cout << "forever" << endl;
            return 0;
        }
    }

    int ans = 0;
    int now = 0;
    for (int i = 0; i < N;)
    {
        if (L <= B[i] && T <= now + A[i])
        {
            ans += (T - now + X);
            if (now + A[i] == T)
                i++;
            now = 0;
        }
        else
        {
            ans += A[i];
            if (L <= B[i])
            {
                now += A[i];
            }
            else
            {
                now = 0;
            }
            i++;
        }
    }

    cout << ans << endl;
    return 0;
}