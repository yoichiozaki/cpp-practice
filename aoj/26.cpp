#include <bits/stdc++.h>
using namespace std;

bool on_paper(int x, int y)
{
    if (x < 0 || 10 <= x || y < 0 || 10 <= y)
        return false;
    return true;
}

int main()
{
    int paper[10][10] = {{}};
    string s;
    while (cin >> s)
    {
        int x = s[0] - '0';
        int y = s[2] - '0';
        int size = s[4] - '0';

        if (size == 1)
        {
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1 + abs(i); j <= 1 - abs(i); j++)
                {
                    if (on_paper(x + i, y + j))
                        paper[x + i][y + j]++;
                }
            }
        }
        else if (size == 2)
        {
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (on_paper(x + i, y + j))
                        paper[x + i][y + j]++;
                }
            }
        }
        else if (size == 3)
        {
            for (int i = -2; i <= 2; i++)
            {
                for (int j = -2 + abs(i); j <= 2 - abs(i); j++)
                {
                    if (on_paper(x + i, y + j))
                        paper[x + i][y + j]++;
                }
            }
        }
    }

    int white = 0, colored = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            colored = max(colored, paper[i][j]);
            if (paper[i][j] == 0)
                white++;
        }
    }
    cout << white << endl;
    cout << colored << endl;
    return 0;
}