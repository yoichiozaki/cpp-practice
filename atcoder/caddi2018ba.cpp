#include <bits/stdc++.h>
using namespace std;

int main()
{
    string N;
    cin >> N;
    int ans = 0;
    for (auto c : N)
    {
        if (c == '2')
            ans++;
    }
    cout << ans << endl;
    return 0;
}