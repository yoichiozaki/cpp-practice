#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> cookie(4, 0);
    cin >> cookie[0] >> cookie[1] >> cookie[2] >> cookie[3];
    for (int bit = 0; bit < (1 << 4); bit++)
    {
        int eaten = 0;
        int left = 0;
        for (int i = 0; i < 4; i++)
        {
            if (bit & (1 << i))
                eaten += cookie[i];
            else
                left += cookie[i];
        }
        if (eaten == left)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}