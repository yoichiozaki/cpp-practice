#include <bits/stdc++.h>

using namespace std;

char base36(int x)
{
    if (x < 10)
        return '0' + x;
    return 'A' + x - 10;
}

int main()
{
    int N;
    cin >> N;
    if (N == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    string ans;
    while (N != 0)
    {
        ans = base36(N % 36) + ans;
        N /= 36;
    }
    cout << ans << endl;
    return 0;
}