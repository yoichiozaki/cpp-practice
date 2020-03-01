#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
    int reversed = 0;
    int _n = n;
    int digit;
    while (_n) {
        digit = _n%10;
        reversed = reversed*10 + digit;
        _n /= 10;
    }
    if (reversed == n) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int A, B; cin >> A >> B;
    int cnt = 0;
    for (int i = A; i <= B; i++) {
        if (check(i)) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}