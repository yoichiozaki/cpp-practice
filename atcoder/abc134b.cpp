#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, D;
    cin >> N >> D;
    if (N % (2 * D + 1) == 0)
        cout << N / (2 * D + 1) << endl;
    else
        cout << N / (2 * D + 1) + 1 << endl;
    return 0;
}
