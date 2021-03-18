#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, W;
    cin >> A >> B >> W;
    int m = 1e9, M = 0;
    for (int n = 1; n <= 1000000; n++)
    {
        if (A * n <= 1000 * W && 1000 * W <= B * n)
        {
            m = min(m, n);
            M = max(M, n);
        }
    }
    if (M == 0)
        cout << "UNSATISFIABLE" << endl;
    else
        cout << m << " " << M << endl;
    return 0;
}