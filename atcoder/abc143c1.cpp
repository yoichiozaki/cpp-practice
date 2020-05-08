#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    s.erase(unique(s.begin(), s.end()), s.end());
    cout << s.size() << endl;
    return 0;
}