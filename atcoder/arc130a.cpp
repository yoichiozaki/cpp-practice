#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    int ans = 0;
    int n = 0;
    for (int j = 0; j < N; j++)
    {
        if (0 < j && S[j] == S[j - 1])
            n += 1;
        else
            n = 0;
        ans += n;
    }
    cout << ans << endl;
    return 0;
}