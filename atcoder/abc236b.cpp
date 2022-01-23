#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int ans = (N * (N + 1)) / 2 * 4;
    for (int i = 0; i < 4 * N - 1; i++)
    {
        int A;
        cin >> A;
        ans -= A;
    }
    cout << ans << endl;
    return 0;
}