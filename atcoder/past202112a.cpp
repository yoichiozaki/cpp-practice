#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    int h, w;
    cin >> h >> w;
    if (H <= h && w <= W)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}