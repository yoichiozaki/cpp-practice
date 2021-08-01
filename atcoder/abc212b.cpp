#include <bits/stdc++.h>

using namespace std;

int main()
{
    string passwd;
    cin >> passwd;
    int x1 = int(passwd[0] - '0');
    int x2 = int(passwd[1] - '0');
    int x3 = int(passwd[2] - '0');
    int x4 = int(passwd[3] - '0');
    if (x1 == x2 && x2 == x3 && x3 == x4)
    {
        cout << "Weak" << endl;
        return 0;
    }
    if (x2 == (x1 + 1) % 10 && x3 == (x2 + 1) % 10 && x4 == (x3 + 1) % 10)
    {
        cout << "Weak" << endl;
        return 0;
    }
    cout << "Strong" << endl;
    return 0;
}