#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int w[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    while (cin >> n)
    {
        for (int bit = 0; bit < (1 << 10); bit++)
        {
            if (bit == n)
            {
                for (int i = 0; i < 10; i++)
                {
                    if ((bit >> i) & 1)
                    {
                        if ((bit >> i) == 1 || (bit >> i) == 0)
                            cout << w[i] << endl;
                        else
                            cout << w[i] << " ";
                    }
                }
            }
        }
    }
    return 0;
}