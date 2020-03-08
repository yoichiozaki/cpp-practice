#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int ret = N;
    for (int i = 0; i <= N; i++) {
        int cc = 0;
        int t = i;
        while (0 < t) {
            cc += t%6;
            t /= 6;
        }
        t = N-i;
        while (0 < t) {
            cc += t%9;
            t /= 9;
        }
        if (cc < ret) {
            ret = cc;
        }
    }
    cout << ret << endl;
    return 0;
}