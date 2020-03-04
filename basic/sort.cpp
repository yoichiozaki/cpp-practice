#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[8] = {8, 3, 7, 1, 4, 6, 2, 5};
    sort(a+1, a+5, greater<int>());
    for (int i = 0; i < 8; i++) {
        cout << a[i] << endl;
    }

    int N, b[100009];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    sort(b, b+N);
    for (int i = 0; i < N; i++) {
        cout << b[i] << endl;
    }
    return 0;
}