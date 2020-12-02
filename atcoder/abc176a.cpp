#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, X, T;
    cin >> N >> X >> T;
    int ret = (N / X) * T;
    if (N % X != 0)
        ret += T;
    cout << ret << endl;
    return 0;
}