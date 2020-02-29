#include <bits/stdc++.h>
using namespace std;

int main(){
    while (1) {
        string s;
        cin >> s;
        if (s == "-") {
            break;
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int h = 0;
            cin >> h;
            s = s.substr(h) + s.substr(0, h);
        }
        cout << s << endl;
    }
    return 0;
}