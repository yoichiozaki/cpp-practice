#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K, A;
    cin >> N >> K >> A;
    int ret = (A + K - 1) % N;
    if (ret == 0)
        ret = N;
    cout << ret << endl;
    return 0;
}