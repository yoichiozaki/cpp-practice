#include <bits/stdc++.h>

using namespace std;

bool used[2005];

int main()
{
    int N;
    cin >> N;
    while (1)
    {
        for (int i = 1; i <= 2 * N + 1; i++)
        {
            if (!used[i])
            {
                cout << i << endl;
                used[i] = true;
                break;
            }
        }
        int ret;
        cin >> ret;
        if (ret == 0)
            break;
        used[ret] = true;
    }
    return 0;
}