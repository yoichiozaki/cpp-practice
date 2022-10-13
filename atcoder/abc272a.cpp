#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int a = 0;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        a += x;
    }
    cout << a << endl;
    return 0;
}