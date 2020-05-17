#include <bits/stdc++.h>
using namespace std;

void convert(int time)
{
    int T = time / (60 * 60);
    int H = (time % (60 * 60)) / 60;
    int S = time % 60;
    cout << setfill('0') << setw(2);
    cout << setfill('0') << setw(2) << T << ":" << setfill('0') << setw(2) << H << ":" << setfill('0') << setw(2) << S << endl;
}

int main()
{
    int T, H, S;
    while (cin >> T >> H >> S)
    {
        if (T == -1 && H == -1 && S == -1)
            break;
        int total = 120 * 60;
        int elapsed = S + 60 * H + 60 * 60 * T;
        int remain = total - elapsed;
        convert(remain);
        convert(remain * 3);
    }
    return 0;
}