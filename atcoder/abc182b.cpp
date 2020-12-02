#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A.begin(), A.end());
    int ans, tmpmax = -1;
    for (int k = 2; k <= A[N - 1]; k++)
    {
        int tmp = 0;
        for (int i = 0; i < N; i++)
            if (A[i] % k == 0)
                tmp++;
        if (tmpmax <= tmp)
        {
            tmpmax = tmp;
            ans = k;
        }
    }
    cout << ans << endl;
    return 0;
}