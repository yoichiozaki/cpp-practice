#include <bits/stdc++.h>
using namespace std;

int main()
{
    char buf[81];
    int sum = 0;
    while (scanf("%s", buf) != EOF)
    {
        int tmp = 0;
        for (int i = 0; buf[i] != '\0'; i++)
        {
            if ('0' <= buf[i] && buf[i] <= '9')
            {
                tmp += 10 * tmp + (buf[i] - '0');
                if (buf[i + 1] == '\0')
                    sum += tmp;
            }
            else
            {
                if ('0' <= buf[i - 1] && buf[i - 1] <= '9')
                {
                    sum += tmp;
                    tmp = 0;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}