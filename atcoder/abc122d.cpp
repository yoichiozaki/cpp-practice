#include <bits/stdc++.h>
using namespace std;

// ACをまとめて扱うと，「TTTA|CTTACTT|TTTT」みたいな文字列で答えが合わないので
// 「右隣にCがあるようなA」の個数をカウントすると問題を読み替える
// さらに「TTACTTA|C」みたいな右端のAの右隣にCがあるようなときのAを除外するために区間[l,r)を考える

int main() {
    int N, Q; cin >> N >> Q;
    string str; cin >> str;

    vector<int> s(N+1, 0); // s[i]: i文字目までに存在する「右隣にCがあるようなA」の個数
    for (int i = 0; i < N; i++) {
        if (i+1 < N && str[i] == 'A' && str[i+1] == 'C') {
            s[i+1] = s[i] + 1;
        } else {
            s[i+1] = s[i];
        }
    }
    for (int q = 0; q < Q; q++) {
        int l, r; cin >> l >> r;
        l--; r--;
        cout << s[r] - s[l] << endl;
    }
    return 0;
}