#include <bits/stdc++.h>
using namespace std;

int search(int a[], int n, int key) {
    int i = 0;
    a[n] = key; // sentinel
    while (a[i] != key) i++;
    return i != n;
}

int main() {
    int i, n, a[10000+1], q, key, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> key;
        if (search(a, n, key)) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}