#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "BOWWOW" << endl;
        return 0;
    }
    int sum = n * (1 + n) / 2;
    bool flag = false;
    for (int i = 2; i * i <= sum; i++)
    {
        if (sum % i == 0)
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "BOWWOW" << endl;
    else
        cout << "WANWAN" << endl;
    return 0;
}