#include <bits/stdc++.h>
using namespace std;

long long cnt;
int l;
int a[1000000];
int n;
vector<int> G;

void insertion_sort(int a[], int n, int g) {
    for (int i = g; i < n; i++) {
        int v = a[i];
        int j = i - g;
        while (0 <= j && v < a[j]) {
            a[j+g] = a[j];
            j -= g;
            cnt++;
        }
        a[j+g] = v;
    }
}

void shell_sort(int a[], int n) {
    for (int h = 1; ; ) {
        if (n < h) break;
        G.push_back(h);
        h = 3*h + 1;
    }

    for (int i = (int)G.size()-1; 0 <= i; i--) {
        insertion_sort(a, n, G[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cnt = 0;
    shell_sort(a, n);
    cout << G.size() << endl;
    for (int i = (int)G.size()-1; 0 <= i; i--) {
        cout << G[i];
        if (i) cout << " ";
    }
    cout << endl;
    cout << cnt << endl;
    for (int i = 0; i < n; i++) cout << a[i] << endl;
    return 0;
}