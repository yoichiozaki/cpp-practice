#include <bits/stdc++.h>
using namespace std;

int main()
{
    int D, N;
    cin >> D >> N;
    if (D == 0)
        cout << N << endl;
    else if (D == 1)
        cout << 100 * N << endl;
    else
        cout << 100 * 100 * N << endl;
    return 0;
}