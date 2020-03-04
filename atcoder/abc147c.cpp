#include <bits/stdc++.h>
using namespace std;

// N人の正直者・不親切な人の分布は2^N通り
// それぞれの状態に対して与えられた証言と矛盾しないかを検査して，矛盾しない場合の内の正直者の最大数を出力
// 0以上2^N未満の整数j = 1以上N以下の整数kに対して人kが正直者でjを2進数表記したときのk-1桁目が1

int N;
int A[20];
int x[20][20];
int y[20][20];

int counter(int x) {
    if(x == 0) return 0;
    return counter(x >> 1) + (x & 1);
}

void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        for(int j = 1; j <= A[i]; j++) {
            cin >> x[i][j] >> y[i][j];
        }
    }
    int ans = 0;
    for(int bits = 1; bits < (1 << N); bits++) {
        bool ok = true;
        for(int i = 1; i <= N; i++) {
            if(!(bits & (1 << (i-1)))) continue;
            for(int j = 1; j <= A[i]; j++) {
                if(((bits >> (x[i][j]-1)) & 1) ^ y[i][j]) ok = false;
            }
        }
        if(ok) ans = max(ans, counter(bits));
    }
    cout << ans << endl;
    return;
}

int main() {
    solve();
    return 0;
}
