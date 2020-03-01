#include <bits/stdc++.h>
using namespace std;

int main() {
    int c11, c12, c13, c21, c22, c23, c31, c32, c33;
    cin >> c11 >> c12 >> c13
        >> c21 >> c22 >> c23
        >> c31 >> c32 >> c33;
    if (c11+c22+c33 == c12+c23+c31 && c11+c22+c33 == c13+c21+c32) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}