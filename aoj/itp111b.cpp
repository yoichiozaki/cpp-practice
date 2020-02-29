#include <bits/stdc++.h>
using namespace std;

// Dice
struct Dice {
    int s[6];
    int &top()    { return s[0]; }
    int &south()  { return s[1]; }
    int &east()   { return s[2]; }
    int &west()   { return s[3]; }
    int &north()  { return s[4]; }
    int &bottom() { return s[5]; }
    void roll(char d) {
        // サイコロを上から見て
        //
        //     *----N----*
        //     |         |
        //     W         E
        //     |         |
        //     *----S----*
        //
        //

        // E: East
        // W: West
        // N: North
        // S: South
        // R: Right
        // L: Left
        string direction = "EWNSRL";
        int rotations[6][4] = {
            {0, 3, 5, 2},
            {0, 2, 5, 3},
            {0, 1, 5, 4},
            {0, 4, 5, 1},
            {1, 2, 4, 3},
            {1, 3, 4, 2}
        };
        for (int i = 0; i < 6; i++) {
            if (direction[i] != d) { continue; }
            int t = s[rotations[i][0]];
            s[rotations[i][0]] = s[rotations[i][1]];
            s[rotations[i][1]] = s[rotations[i][2]];
            s[rotations[i][2]] = s[rotations[i][3]];
            s[rotations[i][3]] = t;
        }
    }
    using ll = long long;
    ll hash() {
        ll res = 0;
        for (int i = 0; i < 6; i++) {
            res = res * 256 + s[i];
            return res;
        }
    }

    bool operator==(const Dice &d) const {
        for (int i = 0; i < 6; i++) {
            if (s[i] != d.s[i]) {
                return false;
            }
        }
        return true;
    }
};

vector<Dice> MakeDices(Dice d) {
    vector<Dice> res;
    for (int i = 0; i < 6; i++) {
        Dice t(d);
        if (i == 1) { t.roll('N'); }
        if (i == 2) { t.roll('S'); }
        if (i == 3) { t.roll('S'); t.roll('S'); }
        if (i == 4) { t.roll('L'); }
        if (i == 5) { t.roll('R'); }
        for (int k = 0; k < 4; k++) {
            res.push_back(t);
            t.roll('E');
        }
    }
    return res;
}

void solve() {
    Dice d;
    for (int i = 0; i < 6; i++) {
        cin >> d.s[i];
    }
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (d.west() == a) {
            d.roll('E');
        }
        if (d.east() == a) {
            d.roll('W');
        }
        while (d.top() != a) {
            d.roll('N');
        }
        while (d.south() != b) {
            d.roll('R');
        }
        cout << d.east() << endl;
    }
}

int main(){
    solve();
    return 0;
}