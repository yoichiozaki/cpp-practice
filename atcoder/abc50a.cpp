#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long A, B;
    char op;
    cin >> A >> op >> B;
    long long ans = 0LL;
    if (op == '+')
        ans = A + B;
    else
        ans = A - B;
    cout << ans << endl;
    return 0;
}