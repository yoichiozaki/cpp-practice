#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, bool> m;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "insert") {
            string a; cin >> a;
            m[a] = true;
        } else if (s == "find") {
            string a; cin >> a;
            if (m.count(a)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
    return 0;
}