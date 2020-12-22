#include <bits/stdc++.h>
using namespace std;

string to_oct(int n)
{
    string s;
    while (n)
    {
        s = to_string(n % 8) + s;
        n /= 8;
    }
    return s;
}

bool check(int n)
{
    string s1 = to_string(n);
    string s2 = to_oct(n);
    if (s1.find("7") == string::npos && s2.find("7") == string::npos)
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (check(i))
            ans++;
    }
    cout << ans << endl;
    return 0;
}