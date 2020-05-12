#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int ans = max<int>({
        10 * A + B + C,
        A + 10 * B + C,
        A + B + 10 * C,
    });
    cout << ans << endl;
    return 0;
}