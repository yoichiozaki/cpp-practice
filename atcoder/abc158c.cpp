#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B; cin >> A >> B;
    int m = 1000000;
    for (int i = 1300; 1 <= i; i--) {
        int x = (int)(i*0.08);
        int y = (int)(i*0.1);
        if (x == A && y == B) {
            m = min(m, i);
        }
    }
    if (m == 1000000) {
        cout << -1 << endl;
    } else {
        cout << m << endl;
    }
    return 0;
}