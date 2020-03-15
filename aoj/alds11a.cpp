#include <bits/stdc++.h>
using namespace std;

void trace(vector<int> a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (0 < i) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

void insertion_sort(vector<int> a, int n) {
    int i, j, v;
    for (i = 1; i < n; i++) {
        v = a[i]; // a[i]の値をvに取っておく
        j = i - 1;
        while (0 <= j && v < a[j]) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        trace(a, n);
    }
}

int main() {
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    trace(a, n);
    insertion_sort(a, n);
    return 0;
}