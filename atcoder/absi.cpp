#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, Y;
    cin >> N >> Y;
    int one = -1, five = -1, ten = -1;
    for (int a = 0; a <= N; a++)
    {
        for (int b = 0; a + b <= N; b++)
        {
            int c = N - a - b;
            if (10000 * a + 5000 * b + 1000 * c == Y)
            {
                ten = a;
                five = b;
                one = c;
            }
        }
    }
    cout << ten << " " << five << " " << one << endl;
    return 0;
}