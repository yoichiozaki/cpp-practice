#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << char(s1[0] - 'a' + 'A') << char(s2[0] - 'a' + 'A') << char(s3[0] - 'a' + 'A') << endl;
    return 0;
}