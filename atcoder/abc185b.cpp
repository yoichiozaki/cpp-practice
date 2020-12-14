#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, T;
    cin >> N >> M >> T;
    int now = 0;
    int charge = N;
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        charge -= (A - now);
        if (charge <= 0)
        {
            cout << "No" << endl;
            return 0;
        }
        now = B;
        charge = min(N, charge + (B - A));
    }
    charge -= (T - now);
    if (charge <= 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}