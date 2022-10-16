#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, A; cin >> N;
    map<int, int> table;
    for (int i = 1; i <= N; i++) {
        cin >> A; table[A]++;
    }
    for (auto iter = table.rbegin(); iter != table.rend(); iter++) {
        cout << iter->second << endl;
    }
    for (int i = 1; i <= N - (int)table.size(); i++) {
        cout << 0 << endl;
    }
    return 0;
}