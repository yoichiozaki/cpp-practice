#include <bits/stdc++.h>
using namespace std;

// 三桁の暗証番号は000-999のどれかでしかないので暗証番号を決め打ちしてそれをSから作れるかを調べる

int main() {
    int N, cnt = 0;
    string S;
    cin >> N >> S;
    for (int i = 0; i < 1000; i++) {
        vector<int> c = {
            i/100, (i/10)%10, i%10
        };
        int f = 0;
        for (int j = 0; j < N; j++) {
            if (S.at(j) == ('0' + c.at(f))) {
                f++;
            }
            if (f == 3) {
                break;
            }
        }
        if (f == 3) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}