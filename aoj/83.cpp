#include <bits/stdc++.h>
using namespace std;

int main()
{
    int year, month, day;
    while (cin >> year >> month >> day)
    {
        if ((year <= 1867) || (year == 1868 && month <= 8) || (year == 1868 && month == 9 && day <= 7))
        {
            printf("pre-meiji\n");
        }
        else if (year <= 1911 || (year == 1912 && month <= 6) || (year == 1912 && month == 7 && day <= 29))
        {
            printf("meiji %d %d %d\n", year - 1868 + 1, month, day);
        }
        else if (year <= 1925 || (year == 1926 && month <= 11) || (year == 1926 && month == 12 && day <= 24))
        {
            printf("taisho %d %d %d\n", year - 1912 + 1, month, day);
        }
        else if (year <= 1988 || (year == 1989 && month == 1 && day <= 7))
        {
            printf("showa %d %d %d\n", year - 1926 + 1, month, day);
        }
        else
        {
            printf("heisei %d %d %d\n", year - 1989 + 1, month, day);
        }
    }
    return 0;
}