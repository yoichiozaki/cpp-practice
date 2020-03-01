#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    for (int i = 0; i <= 26; i++) {
        for (int j = 0; j <= 13; j++) {
            if (4*i + 7*j == N) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}