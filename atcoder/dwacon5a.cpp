#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    int s = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        s += A[i];
    }
    int diff = INT_MAX / 2;
    int ans = N + 1;
    for (int i = 0; i < N; i++)
    {
        if (abs(s - N * A[i]) < diff)
        {
            diff = abs(s - N * A[i]);
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}