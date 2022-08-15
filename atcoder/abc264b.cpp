#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, C; cin >> R >> C;
    if (max(abs(R - 8), abs(C - 8)) % 2)
        cout << "black" << endl;
    else
        cout << "white" << endl;
    return 0;
}