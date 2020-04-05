#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, k; cin >> a >> b >> k;
    if (b < a) swap(a, b);
    int cnt = 0;
    for (int i = a; 1 <= i; i--) {
        if (a%i == 0 && b%i == 0) {
            cnt++;
            if (cnt == k) {
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}