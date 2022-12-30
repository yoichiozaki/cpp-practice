#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int type; cin >> type;
        if (type == 1) {
            int k, x; cin >> k >> x;
            A[k - 1] = x;
        } else {
            int k; cin >> k;
            cout << A[k - 1] << endl;
        }
    }
    return 0;
}