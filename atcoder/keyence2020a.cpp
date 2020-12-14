#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W, N;
    cin >> H >> W >> N;
    int M = max(H, W);
    cout << (N + M - 1) / M << endl;
    return 0;
}