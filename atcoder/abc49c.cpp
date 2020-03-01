#include <bits/stdc++.h>
using namespace std;

string divide[4] = {"dream", "dreamer", "erase", "eraser"};

int main(){
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    for (int i = 0; i < 4; i++) {
        reverse(divide[i].begin(), divide[i].end());
    }
    bool flag = true;
    for (int i = 0; i < (int)S.size(); ) {
        bool _flag = false;
        for (int j = 0; j < 4; j++) {
            string d = divide[j];
            if (S.substr(i, d.size()) == d) {
                _flag = true;
                i += d.size();
            }
        }
        if (!_flag) {
            flag = false;
            break;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
     return 0;
}
