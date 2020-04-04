#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(3, 0);
    for (int i = 0; i < 3; i++) cin >> a[i];
    swap(a[0], a[1]);
    swap(a[0], a[2]);
    for (int i = 0; i < 3; i++) {
        if (i != 3) cout << a[i] << " " << endl;
        else cout << a[i] << endl;
    }
    return 0;
}