#include <bits/stdc++.h>
using namespace std;

using State = string::iterator;

int number(State &begin);
int factor(State &begin);
int expression(State &begin);

int main(void)
{
    int N;
    std::cin >> N;

    while (N--)
    {
        std::string s;
        std::cin >> s;
        State begin = s.begin();
        int ans = expression(begin);
        std::cout << ans << std::endl;
    }
    return 0;
}

int number(State &begin)
{
    int ret = 0;

    while (isdigit(*begin))
    {
        ret *= 10;
        ret += *begin - '0';
        begin++;
    }

    return ret;
}

int factor(State &begin)
{
    if (*begin == '(')
    {
        begin++;
        int ret = expression(begin);
        begin++;
        return ret;
    }
    else
    {
        return number(begin);
    }
}

int expression(State &begin)
{
    int num = factor(begin);
    int sum = 0;

    for (;;)
    {
        char ch = *begin;
        begin++;
        if (ch == '+')
        {
            sum += num;
            num = factor(begin);
        }
        else if (ch == '-')
        {
            sum += num;
            num = -factor(begin);
        }
        else if (ch == '*')
        {
            num *= factor(begin);
        }
        else if (ch == '/')
        {
            num /= factor(begin);
        }
        else
        {
            begin--;
            break;
        }
    }
    return sum + num;
}