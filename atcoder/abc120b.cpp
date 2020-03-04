#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, K; cin >> A >> B >> K;
    if (B < A) {
        swap(A, B);
    }
    int cnt = 1;
    for (int i = A; 1 <= i; i--) {
        if (A%i == 0 && B%i == 0) {
            if (cnt == K) {
                cout << i << endl;
                return 0;
            } else {
                cnt++;
            }
        }
    }
    return 0;
}