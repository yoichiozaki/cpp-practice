#include <bits/stdc++.h>

using namespace std;

int factorial(int i)
{
    return i ? factorial(i - 1) * i : 1;
}

int main()
{
    int P;
    cin >> P;
    int ans = 0;
    for (int i = 1; i <= 10; i++)
    {
        int d = factorial(i + 1);
        int res = P % d;
        ans += res / factorial(i);
        P -= res;
    }
    cout << ans << endl;
    return 0;
}