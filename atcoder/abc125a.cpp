#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a, t;
    int b;
    cin >> a >> b >> t;
    int cnt = 0;
    double tic = 0.0;
    for (int i = 1; tic + a * i < t + 0.5; i++)
    {
        cnt += b;
    }
    cout << cnt << endl;
    return 0;
}