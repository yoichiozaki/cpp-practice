#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    cout << (W - 2 + 1) * (H - 1 + 1) + (W - 1 + 1) * (H - 2 + 1) << endl;
    return 0;
}