#include <bits/stdc++.h>

using namespace std;

int check(int x)
{
    int ret = 0;
    x -= (x / 500) * 500;
    x -= (x / 100) * 100;
    ret += (x / 50);
    x -= (x / 50) * 50;
    x -= (x / 10) * 10;
    ret += (x / 5);
    x -= (x / 5) * 5;
    x -= (x / 1) * 1;
    return ret;
}

int main()
{
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int A, B;
        cin >> A >> B;
        ans += check(B - A);
    }
    cout << ans << endl;
    return 0;
}