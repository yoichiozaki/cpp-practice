#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    set<pair<int ,int>> follows;
    for (int i = 0; i < Q; i++) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) follows.emplace(a, b);
        else if (t == 2) follows.erase({a, b});
        else cout << (follows.count({a, b}) && follows.count({b, a}) ? "Yes" : "No") << endl;
    } 
    return 0;
}