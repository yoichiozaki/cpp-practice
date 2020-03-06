#include <bits/stdc++.h>
using namespace std;

int n, m, k;
bool talktive[12][12];

int main() {
    srand((unsigned)time(NULL));
    cout << fixed << setprecision(30);

    cin >> n >> m >>k;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        talktive[a][b] = true;
        talktive[b][a] = true;
    }

    vector<int> seats(n, 0);
    for (int i = 0; i < n; i++) {
        seats[i] = i;
    }

    int ok = 0, ng = 0;
    for (int i = 0; i < 500001; i++) {
        vector<int> s = seats;
        bool ngflag = false;
        for (int i =0; i < k; i++) {
            while (1) {
                int a = rand() % n;
                int b = rand() % n;
                if (a != b) {
                    swap(s[a], s[b]);
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (talktive[s[i]][s[(i+1)%n]]) {
                ngflag = true;
                break;
            }
        }
        if (ngflag) {
            ng++;
        } else {
            ok++;
        }
    }
    cout << 1.0 * ok/(ok+ng) << endl;
    return 0;
}