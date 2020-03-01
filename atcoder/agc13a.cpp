#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    int a;
    int prev;
    enum {
        FLAT = 0,
        UP = 1,
        DOWN = 2
    };
    int status = FLAT;
    cin >> prev;

    int ans = 0;
    for (int i = 0; i < N-1; i++) {
        cin >> a;
        if (status == FLAT) {
            if (prev < a) {
                status = UP;
                ans++;
            } else if (prev == a) {
                status == FLAT;
            } else {
                status = DOWN;
                ans++;
            }
        } else {
            if (prev < a && status == DOWN) {
                status = FLAT;
            } else if (a < prev && status == UP) {
                status = FLAT;
            }
        }
        prev = a;
    }
    if (status == FLAT) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}
