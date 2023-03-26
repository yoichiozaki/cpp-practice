#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector <string> b(r);
    for (string &s: b) cin >> s;
    
    vector blasted(r, vector<bool>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!isdigit(b[i][j])) continue;
            int power = b[i][j] - '0';
            for (int ni = 0; ni < r; ni++) {
                for (int nj = 0; nj < c; nj++) {
                    if (abs(i - ni) + abs(j - nj) <= power) blasted[ni][nj] = true;
                }
            }
        }
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (blasted[i][j]) b[i][j] = '.';
        }
    }
    
    for (string &s: b) cout << s << '\n';
    return 0;
}