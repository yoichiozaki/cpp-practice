#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    cout << setprecision(12);
    if (X <= A)
        cout << 1.0 << endl;
    else if (X <= B)
    {
        double ret = C;
        ret /= (B - A);
        cout << ret << endl;
    }
    else
        cout << 0.0 << endl;
    return 0;
}