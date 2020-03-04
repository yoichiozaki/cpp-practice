#include <bits/stdc++.h>
using namespace std;

int N, a[100009];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N-i; j++) {
            if (a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << a[i] << endl;
    }
    return 0;
}