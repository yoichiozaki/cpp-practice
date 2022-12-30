#include <bits/stdc++.h>

using namespace std;

bool is_uppercase(char c) {
    return 'A' <= c && c <= 'Z';
}

bool is_digit(char c) {
    return '0' <= c && c <= '9';
}

int main() {
    string S; cin >> S;
    if (!is_uppercase(S.front())) {
        cout << "No" << endl;
        return 0;
    }
    if (!is_uppercase(S.back())) {
        cout << "No" << endl;
        return 0;
    }
    if (S.size() != 8) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1; i < 7; i++) {
        if (!is_digit(S[i])) {
            cout << "No" << endl;
            return 0;
        }
    }
    if (S[1] == '0') {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}