#include <bits/stdc++.h>

using namespace std;

int main()
{
    char ca, cb, cc;
    cin >> ca >> cb >> cc;
    int a = ca - '0';
    int b = cb - '0';
    int c = cc - '0';
    cout << (a + b + c) * 111 << endl;
    return 0;
}