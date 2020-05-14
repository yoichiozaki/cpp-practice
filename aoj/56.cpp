#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    bool prime[50000] = {};
    for (int i = 2; i < 50000; i++)
        prime[i] = is_prime(i);
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int ans = 0;
        for (int i = 1; i <= n / 2; i++)
        {
            if (prime[i] && prime[n - i])
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}