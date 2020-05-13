#include <bits/stdc++.h>
using namespace std;
char str[15];
int use[12];
bool solve(int a)
{
    if (a == 0)
        return true;
    for (int i = 0; i < 9; i++)
    {
        if (use[i])
        {
            if (use[i] >= 3)
            {
                use[i] -= 3;
                bool res = solve(a - 3);
                use[i] += 3;
                if (res)
                    return true;
            }
            if (use[i] >= 2 && a % 3 == 2)
            {
                use[i] -= 2;
                bool res = solve(a - 2);
                use[i] += 2;
                if (res)
                    return true;
            }
            if (use[i] && use[i + 1] && use[i + 2])
            {
                use[i]--;
                use[i + 1]--;
                use[i + 2]--;
                bool res = solve(a - 3);
                use[i]++;
                use[i + 1]++;
                use[i + 2]++;
                if (res)
                    return true;
            }
            return false;
        }
    }
}
int main()
{
    while (~scanf("%s", str))
    {
        for (int i = 0; i < 9; i++)
            use[i] = 0;
        for (int i = 0; i < 13; i++)
            use[str[i] - '1']++;
        bool ok = false;
        for (int i = 0; i < 9; i++)
        {
            if (use[i] == 4)
                continue;
            use[i]++;
            if (solve(14))
            {
                if (ok)
                    printf(" ");
                printf("%d", i + 1);
                ok = true;
            }
            use[i]--;
        }
        if (!ok)
            printf("0");
        printf("\n");
    }
}