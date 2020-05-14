#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a;
    while (cin >> a)
    {
        vector<double> A(10);
        A[0] = a;
        for (int i = 1; i <= 9; i++)
        {
            if (i % 2 == 1)
            {
                A[i] = A[i - 1] * 2.0;
            }
            else
            {
                A[i] = A[i - 1] / 3.0;
            }
        }
        double ans = 0.0;
        for (int i = 0; i < 10; i++)
            ans += A[i];
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}