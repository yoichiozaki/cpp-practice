#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b; cin >> a >> b;
    string c = a + b;
    if (c.size() <= 10) {
        cout << c << endl;
    } else {
        cout << c.substr(0, 10) << endl;
    }

    string s;
    cin >> s;
    for (int i =0 ; i < s.size(); i+= 2) {
        s[i] = 'x';
    }
    cout << s << endl;
}