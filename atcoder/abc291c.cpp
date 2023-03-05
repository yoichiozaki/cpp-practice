#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    set<pair<int, int>> visited({{0, 0}});
    int x = 0, y = 0;
    for (auto ch: S) {
        if (ch == 'U') y++;
        if (ch == 'D') y--;
        if (ch == 'R') x++;
        if (ch == 'L') x--;
        if (visited.find({x, y}) != visited.end()) {
            cout << "Yes" << endl;
            return 0;
        }
        visited.insert({x, y});
    }
    cout << "No" << endl;
    return 0;
}