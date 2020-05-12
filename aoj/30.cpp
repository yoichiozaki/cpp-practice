#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;

void rec(int depth, int last_prev, int sum)
{
    if (depth == n + 1)
        return;
    else if (depth == n)
    {
        if (sum == s)
            cnt++;
    }
    else
    {
        for (int i = last_prev + 1; i <= 9; i++)
        {
            rec(depth + 1, i, sum + i);
        }
    }
}

int main()
{
    while (cin >> n >> s)
    {
        cnt = 0;
        if (n == 0 && s == 0)
            break;
        rec(0, -1, 0);
        cout << cnt << endl;
    }
    return 0;
}