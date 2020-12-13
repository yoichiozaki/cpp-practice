#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long S, P;
    cin >> S >> P;
    for (long long N = 1LL; N * N <= P; N++)
    {
        long long M = P / N;
        if (N + M == S)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}