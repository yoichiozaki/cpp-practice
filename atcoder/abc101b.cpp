#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    string s = to_string(n);
    long long a = 0;
    for (int i = 0; i < s.size(); i++)
        a += s[i] - '0';
    if (n % a == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}