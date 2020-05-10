#include <bits/stdc++.h>
using namespace std;

const int inf = 1012345678;

int main()
{
    vector<int> A(5);
    cin >> A[0] >> A[1] >> A[2] >> A[3] >> A[4];
    vector<int> P = {0, 1, 2, 3, 4};
    int ans = inf;
    do
    {
        int tmp = 0;
        for (int i = 0; i < 5; i++)
        {
            while (tmp % 10 != 0)
                tmp++; // 料理が注文可能になる時刻まで待機
            tmp += A[P[i]];
        }
        ans = min(ans, tmp);
    } while (next_permutation(P.begin(), P.end()));
    cout << ans << endl;
    return 0;
}
