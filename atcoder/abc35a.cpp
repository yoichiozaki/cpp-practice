#include <bits/stdc++.h>
using namespace std;

int main()
{
    int W, H;
    cin >> W >> H;
    if (W * 3 == H * 4)
        cout << "4:3" << endl;
    else
        cout << "16:9" << endl;
    return 0;
}