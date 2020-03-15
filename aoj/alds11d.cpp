#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> R(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }
    int maxv = -2000000000;
    int minv = R[0];

    for (int i = 1; i < n; i++) {
        maxv = max(maxv, R[i] - minv);
        minv = min(minv, R[i]);
    }

    cout << maxv << endl;
}