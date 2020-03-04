#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[10] = {1, 2, 3, 4, 1, 2, 3, 1, 2, 1};
    cout << count(a, a+10, 1) << endl;
    cout << count(a, a+10, 2) << endl;

    int b[1009], N, Q;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> b[i];
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        cout << count(b+l, b+r+1, x) << endl;
    }
    return 0;
}