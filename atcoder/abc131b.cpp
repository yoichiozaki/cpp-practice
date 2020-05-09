#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, A;
    cin >> N >> A;
    int L = A;
    int R = A + N - 1;
    int eat;
    if (R <= 0)
        eat = R;
    else if (0 <= L)
        eat = L;
    else
        eat = 0;

    int ans = (R + L) * (R - L + 1) / 2 - eat;
    cout << ans << endl;
    return 0;
}