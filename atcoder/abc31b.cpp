#include <bits/stdc++.h>
using namespace std;

int main()
{
    int L, H;
    cin >> L >> H;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a < L)
            cout << L - a << endl;
        else if (L <= a && a <= H)
            cout << 0 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}