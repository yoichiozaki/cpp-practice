#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> vec(N, 0);
    for (int i = 0; i < N; i++) {
        vec.at(i) = i+1;
    }

    vector<int> p(N);
    vector<int> q(N);
    for (int i = 0; i < N; i++) {
        cin >> p.at(i);
    }
    for (int i = 0; i < N; i++) {
        cin >> q.at(i);
    }

    int pidx = 1;
    int qidx = 1;
    do {
        if (p != vec) {
            pidx++;
        } else {
            break;
        }
    } while (next_permutation(vec.begin(), vec.end()));

    sort(vec.begin(), vec.end());
    do {
        if (q != vec) {
            qidx++;
        } else {
            break;
        }
    } while (next_permutation(vec.begin(), vec.end()));

    cout << abs(pidx - qidx) << endl;
    return 0;
}
