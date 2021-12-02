#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long A, B, C;
    cin >> A >> B >> C;
    long long X = 1;
    for (long long i = 1; i <= B; i++)
        X *= C;
    if (A < X)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}