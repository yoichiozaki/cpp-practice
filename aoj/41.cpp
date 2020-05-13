#include <bits/stdc++.h>
using namespace std;

int perm[4];
char e[] = "+-*";
int main()
{
    int a, b, c, d;
    while (scanf("%d%d%d%d", &a, &b, &c, &d), a + b + c + d)
    {
        perm[0] = a;
        perm[1] = b;
        perm[2] = c;
        perm[3] = d;
        std::sort(perm, perm + 4);
        bool ok = false;
        do
        {
            for (int i = 0; !ok && i < 3 * 3 * 3; i++)
            {
                int val = perm[0];
                int m = i;
                for (int j = 0; j < 3; j++)
                {
                    switch (m % 3)
                    {
                    case 0:
                        val += perm[j + 1];
                        break;
                    case 1:
                        val -= perm[j + 1];
                        break;
                    case 2:
                        val *= perm[j + 1];
                        break;
                    }
                    m /= 3;
                }
                if (val == 10)
                {
                    ok = true;
                    m = i;
                    printf("(((%d", perm[0]);
                    for (int j = 0; j < 3; j++)
                    {
                        printf("%c%d)", e[m % 3], perm[j + 1]);
                        m /= 3;
                    }
                    printf("\n");
                }
            }
            for (int i = 0; !ok && i < 3; i++)
            {
                for (int j = 0; !ok && j < 3; j++)
                {
                    for (int k = 0; !ok && k < 3; k++)
                    {
                        int val1 = perm[0];
                        int val2 = perm[2];
                        switch (i)
                        {
                        case 0:
                            val1 += perm[1];
                            break;
                        case 1:
                            val1 -= perm[1];
                            break;
                        case 2:
                            val1 *= perm[1];
                            break;
                        }
                        switch (j)
                        {
                        case 0:
                            val2 += perm[3];
                            break;
                        case 1:
                            val2 -= perm[3];
                            break;
                        case 2:
                            val2 *= perm[3];
                            break;
                        }
                        switch (k)
                        {
                        case 0:
                            val1 += val2;
                            break;
                        case 1:
                            val1 -= val2;
                            break;
                        case 2:
                            val1 *= val2;
                            break;
                        }
                        if (val1 == 10)
                        {
                            ok = true;
                            printf("((%d%c%d)%c(%d%c%d))\n", perm[0], e[i], perm[1], e[k], perm[2], e[j], perm[3]);
                        }
                    }
                }
            }
        } while (!ok && next_permutation(perm, perm + 4));
        if (!ok)
            printf("0\n");
    }
}