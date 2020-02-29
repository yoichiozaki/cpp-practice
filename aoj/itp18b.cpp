#include <bits/stdc++.h>
using namespace std;

int main(){
    string n;
    while (cin >> n) {
        if (n == "0") {
            break;
        }
        int ans = 0;
        for (int i = 0; i < (int)n.size(); i++) {
            ans += (int)n.at(i) - '0';
        }
        cout << ans <<endl;
    }
    return 0;
}