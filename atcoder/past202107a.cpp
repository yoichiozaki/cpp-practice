#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    long long digit_sum = 0;
    for (int i = 0; i <= 13; i += 2)
    {
        digit_sum += s[i] - '0';
    }
    digit_sum *= 3;
    for (int i = 1; i <= 13; i += 2)
    {
        digit_sum += s[i] - '0';
    }
    digit_sum %= 10;
    if (digit_sum == s[14] - '0')
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}