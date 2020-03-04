#include <bits/stdc++.h>
using namespace std;

int main() {
    srand((unsigned)time(NULL));
    cout << rand() % 6 + 1 << endl;

    if (rand() % 10 <= 8) {
        cout << "Yay!" << endl;
    } else {
        cout << ";(" << endl;
    }

    return 0;
}