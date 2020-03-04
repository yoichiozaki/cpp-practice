#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[8] = {8, 3, 7, 1, 4, 6, 2, 5};
    reverse(a+2, a+7);
    for (int i = 0; i < 8; i++) {
        cout << a[i] << endl;
    }

    int N, b[1009];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    reverse(b, b+N);
    for (int i = 0; i < N; i++) {
        cout << b[i] << endl;
    }
    return 0;
}