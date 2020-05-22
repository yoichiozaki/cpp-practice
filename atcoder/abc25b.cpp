#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        string s;
        int d;
        cin >> s >> d;
        if (s == "East")
        {
            if (d < A)
                ans += A;
            else if (A <= d && d <= B)
                ans += d;
            else
                ans += B;
        }
        else
        {
            if (d < A)
                ans -= A;
            else if (A <= d && d <= B)
                ans -= d;
            else
                ans -= B;
        }
    }
    if (ans < 0)
        cout << "West " << abs(ans) << endl;
    else if (0 < ans)
        cout << "East " << ans << endl;
    else
        cout << 0 << endl;
    return 0;
}
