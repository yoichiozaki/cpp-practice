#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;
    int cnt = 0;
    while (N != 0)
    {
        N /= K;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}