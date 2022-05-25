#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << 297 << endl;
    for (int i = 1; i <= 99; i++) {
        cout << i << " ";
        cout << i * 100 << " ";
        cout << i * 10000 << (i == 99 ? "\n" : " ");
    }
    return 0;
}