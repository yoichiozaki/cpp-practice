#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 1 && A[i] % 2 == 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}