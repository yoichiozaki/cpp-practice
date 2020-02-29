#include <bits/stdc++.h>
using namespace std;

int main() {
    while(1) {
        int a, b;
        char op;
        cin >> a >> op >> b;
        if (op == '?') {
            break;
        }
        if (op == '+') {
            cout << a + b << endl;
        } else if (op == '-') {
            cout << a - b << endl;
        } else if (op == '*') {
            cout << a * b << endl;
        } else {
            cout << a / b << endl;
        }
    }

    return 0;
}