#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int dp[1000000] = {};

int main()
{
    int n;
    for (int i = 2; i <= 1000000; i++)
    {
        if (is_prime(i))
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = dp[i - 1];
    }
    while (cin >> n)
    {
        cout << dp[n] << endl;
    }
    return 0;
}