#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> vec.at(i);
    }
    int res = 0;
    while (1) {
        bool flag = false;
        for (int i = 0; i < N; i++) {
            if (vec.at(i)%2 != 0) {
                flag = true;
            }
        }
        if (flag) {
            break;
        }
        for (int i = 0; i < N; i++) {
            vec.at(i) /= 2;
        }
        res += 1;
    }
    cout << res << endl;
}