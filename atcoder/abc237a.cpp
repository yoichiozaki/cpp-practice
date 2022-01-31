#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long X = 1ll << 31;
    if (-X <= N && N < X)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}