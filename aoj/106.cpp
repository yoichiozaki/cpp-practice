#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        int ans = 1000000;
        for (int a = 0; a <= 50; a++)
        {
            for (int b = 0; b <= 50; b++)
            {
                for (int c = 0; c <= 50; c++)
                {
                    int sum = (380 * (5 * (a / 5))) * 8 / 10 + (a % 5) * 380;
                    sum += (550 * (4 * (b / 4))) * 85 / 100 + (b % 4) * 550;
                    sum += (850 * (3 * (c / 3))) * 88 / 100 + (c % 3) * 850;
                    if (a * 200 + b * 300 + c * 500 == n)
                        ans = min(ans, sum);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}