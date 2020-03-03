#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int a, b, c, d;
    a = (int)(s[0] - '0');
    b = (int)(s[1] - '0');
    c = (int)(s[2] - '0');
    d = (int)(s[3] - '0');
    if (a-b-c-d == 7) {
        cout << a << "-" << b << "-" << c << "-" << d << "=7" << endl;
    } else if (a-b-c+d == 7) {
        cout << a << "-" << b << "-" << c << "+" << d << "=7" << endl;
    } else if (a-b+c-d == 7) {
        cout << a << "-" << b << "+" << c << "-" << d << "=7" << endl;
    } else if (a-b+c+d == 7) {
        cout << a << "-" << b << "+" << c << "+" << d << "=7" << endl;
    } else if (a+b-c-d == 7) {
        cout << a << "+" << b << "-" << c << "-" << d << "=7" << endl;
    } else if (a+b-c+d == 7) {
        cout << a << "+" << b << "-" << c << "+" << d << "=7" << endl;
    } else if (a+b+c-d == 7) {
        cout << a << "+" << b << "+" << c << "-" << d << "=7" << endl;
    } else if (a+b+c+d == 7) {
        cout << a << "+" << b << "+" << c << "+" << d << "=7" << endl;
    }
    return 0;
}
