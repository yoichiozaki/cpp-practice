#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
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
    int n;
    while (cin >> n)
    {
        int n1 = n - 1;
        while (!isPrime(n1))
        {
            n1--;
        }
        int n2 = n + 1;
        while (!isPrime(n2))
        {
            n2++;
        }
        cout << n1 << " " << n2 << endl;
    }
    return 0;
}