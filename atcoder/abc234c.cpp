#include <bits/stdc++.h>

using namespace std;

string convert(long long x)
{
    string ret;
    while (0 < x)
    {
        ret.push_back('0' + (x % 2));
        x /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    long long K;
    cin >> K;
    string s = convert(K);
    for (auto &ch : s)
    {
        if (ch == '1')
            cout << '2';
        else
            cout << '0';
    }
    cout << endl;
    return 0;
}