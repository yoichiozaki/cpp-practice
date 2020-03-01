#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> d(110, 0);
    for (int i = 0; i < N; i++) {
        cin >> d.at(i);
    }
    vector<int> bucket(110, 0);
    for (int i = 0; i < N; i++) {
        bucket.at(d.at(i))++;
    }
    int res = 0;
    for (int i = 1; i <= 100; i++) {
        if (bucket.at(i)) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}