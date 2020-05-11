#include <bits/stdc++.h>
using namespace std;

int main()
{
    int month, day;
    int d[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string s[] = {
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
    };
    while (cin >> month >> day)
    {
        if (month == 0)
            break;
        int sum = 0;
        for (int i = 1; i < month; i++)
            sum += d[i - 1];
        sum += day - 1;
        cout << s[sum % 7] << endl;
    }
    return 0;
}