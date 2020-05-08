#include <bits/stdc++.h>
using namespace std;

long long N;

void rec(long long current, int use_flag, long long &counter)
{
    if (N < current)
        return;
    if (use_flag == 0b111)
        counter++;

    rec(current * 10 + 7, use_flag | 0b001, counter);
    rec(current * 10 + 5, use_flag | 0b010, counter);
    rec(current * 10 + 3, use_flag | 0b100, counter);
}

int main()
{
    cin >> N;
    long long res = 0;
    rec(0, 0, res);
    cout << res << endl;
    return 0;
}