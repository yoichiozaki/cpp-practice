#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    cout << (1900 * M + 100 * (N - M)) * (1 << M) << endl;
    return 0;
}