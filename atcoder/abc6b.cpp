#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> memo(n + 10, 0);
    memo[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        memo[i] = (((memo[i - 3] % 10007) + (memo[i - 2] % 10007)) % 10007 + (memo[i - 1] % 10007)) % 10007;
    }
    cout << memo[n] << endl;
    return 0;
}