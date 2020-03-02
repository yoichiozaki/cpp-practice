#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W; cin >> H >> W;
    vector<vector<char>> board(55, vector<char>(55));
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> board.at(i).at(j);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (board.at(i).at(j) == '#' &&
            board.at(i).at(j-1) != '#' &&
            board.at(i-1).at(j) != '#' &&
            board.at(i).at(j+1) != '#' &&
            board.at(i+1).at(j) != '#') {
                cnt++;
            }
        }
    }
    cout << (cnt == 0 ? "Yes" : "No") << endl;
    return 0;
}
