#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    swap(a, b);
    cout << a << " " << b << endl;

    int N, c[1009];
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N-i; j++) {
            if (c[j] > c[j+1]) {
                swap(c[j], c[j+1]);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << c[i] << endl;
    }
    return 0;
}