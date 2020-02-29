#include <bits/stdc++.h>
using namespace std;

int main(){
    string w, s;
    cin >> w;
    int ans;
    while (1) {
        cin >> s;
        if (s == "END_OF_TEXT") {
            break;
        }
        string sl, wl;
        for (int i = 0; i < (int)s.size(); i++) {
            sl += tolower(s[i]);
        }for (int i = 0; i < (int)w.size(); i++) {
            wl += tolower(w[i]);
        }
        if (sl == wl) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}