#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<bool> vol(N + 2, false);
    vector<int> books(N);
    int can_sell = 0;
    for (int i = 0; i < N; i++) {
        cin >> books[i];
        if (books[i] >= vol.size()) can_sell += 1;
        else if (vol[books[i]] != 0) can_sell += 1;
        else vol[books[i]] = true;
    }
    int left = 1, right = N + 1;
    while (1) {
        while (vol[left]) left += 1;
        while (right != 0 && !vol[right]) right -= 1;
        if (can_sell >= 2) {
            can_sell -= 2;
            vol[left] = true;
        } else {
            if (right <= left) break;
            vol[right] = false;
            can_sell += 1;
        }
    }
    cout << left - 1 << endl;
    return 0;
}