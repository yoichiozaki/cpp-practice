#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    double ans = 0.0, A;
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        ans += 1.0 / A;
    }
    ans = 1.0 / ans;
    cout << fixed << setprecision(16) << ans << endl;
    return 0;
}
