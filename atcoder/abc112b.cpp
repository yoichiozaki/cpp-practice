#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, T;
    cin >> N >> T;
    int minc = 1001;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int c, t;
        cin >> c >> t;
        if (T < t)
            continue;
        if (c < minc)
        {
            ans = i;
            minc = c;
        }
    }
    if (minc == 1001)
        cout << "TLE" << endl;
    else
        cout << minc << endl;
    return 0;
}