#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if (a % 2 == 0) {
            cout << a;
        }
        if (i != N - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    return 0;
}