#include <bits/stdc++.h>
using namespace std;

int main(){
	while (1) {
        int m, f, r;
        cin >> m >> f >> r;
        if (m == -1 && f == -1 && r == -1) {
            break;
        }
        if (m == -1 || f == -1) {
            cout << "F" << endl;
            continue;
        } else if (80 <= m + f) {
            cout << "A" << endl;
            continue;
        } else if (65 <= m + f && m + f < 80) {
            cout << "B" << endl;
            continue;
        } else if (50 <= m + f && m + f < 65) {
            cout << "C" << endl;
            continue;
        } else if (30 <= m + f && m + f < 50) {
            if (50 <= r) {
                cout << "C" << endl;
                continue;
            } else {
                cout << "D" << endl;
                continue;
            }
        } else if (m + f < 30) {
            cout << "F" << endl;
            continue;
        }
    }
}