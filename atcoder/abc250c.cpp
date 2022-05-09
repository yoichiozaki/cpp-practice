#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> balls(N + 1);
    vector<int> position(N + 1);
    for (int i = 1; i <= N; i++) {
        balls[i] = i;
        position[i] = i;
    }
    int Q; cin >> Q;
    for (int _ = 0; _ < Q; _++) {
        int x; cin >> x;
        int p0 = position[x];
        int p1 = p0;
        if (p0 != N) p1 += 1;
        else p1 -= 1;
        int b0 = balls[p0];
        int b1 = balls[p1];
        swap(balls[p0], balls[p1]);
        swap(position[b0], position[b1]);
    }
    for (int i = 1; i <= N; i++) {
        if (i != 1) cout << " ";
        cout << balls[i];
    }
    cout << endl;
    return 0;
}