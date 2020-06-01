#include <bits/stdc++.h>
using namespace std;

std::ostream &operator<<(std::ostream &dest, __int128_t value)
{
    std::ostream::sentry s(dest);
    if (s)
    {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do
        {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0)
        {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len)
        {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

__int128 parse(string &s)
{
    __int128 ret = 0;
    for (int i = 0; i < s.length(); i++)
        if ('0' <= s[i] && s[i] <= '9')
            ret = 10 * ret + s[i] - '0';
    return ret;
}

int main()
{
    int N;
    cin >> N;
    __int128 x = 1;
    for (int i = 0; i < N; i++)
    {
        __int128 a;
        scanf("%jd", &a);
        if (a == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        x *= a;
    }
    if (1000000000000000000 < x)
        cout << -1 << endl;
    else
        cout << x << endl;
}