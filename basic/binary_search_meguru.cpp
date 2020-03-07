#include <bits/stdc++.h>
using namespace std;

// 二分探索は単純でありながら効率がいいアルゴリズムとして有名．
// たいてい教科書などで遭遇する「二分探索」は「ソート済みの配列の中から
// 目的の値を高速に探索するアルゴリズム」として説明される．が，二分探索は
// もっと広い適用範囲を持っている．
// 二分探索の計算時間：「n個の要素からなるソート済み配列から目的の値を探索する」問題では，単純な線形探索ではO(n)かかるところが二分探索すればO(log n)で済む

vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

// 探索対象の値keyのindexを返す．配列中に存在していなければ-1を返す．
// int binary_search(int key) {
//     int left = 0;
//     int right = (int)a.size()-1;

//     while (left <= right) {
//         int mid = left + (right + left) / 2;
//         if (a[mid] == key) {
//             return mid;
//         } else if (key < a[mid]) {
//             right = mid - 1;
//         } else if (a[mid] < key) {
//             left = mid + 1;
//         }
//     }
//     return -1;
// }

// std::lower_bound(): 配列aに対してkey以上となる最小のindexを返す
// std::upper_bound(): 配列aに対してkeyより大きくなる最小のindexを返す
// これらの関数を用いることで
// - 配列aの中に値keyが存在していなくてもkeyがaの中で何番目に小さいかがわかる
// - 配列aの中に値keyが複数存在していてもそのうちの最小のindexを取ってこれる
// - 配列aの中に値keyと等しい要素がいくつあるのかもわかる

// std::lower_bound()は「key <= a[index]」を満たす最小のindexを求めるとも言える
// 二分探索はある条件Aを満たす最小のxを見つけるアルゴリズムとして一般化できる．
// - x = leftは条件を満たさない
// - x = rightは条件を満たす
// - 条件Aを満たすかどうかについては単調性がある（単調性がなくても実は大丈夫）
//     - 求めたい境目を境目にして「そこより左は全部条件を満たさない・そこより右は全て条件を満たす」という単調性を仮定する
//     - 単調性を仮定しない場合だと，条件を満たす満たさないの境目が複数存在してそのうちの1つを見つけられる: f(x) = 0なるxのどれか1つを求める感じになる

// leftは「常に条件を満たさない」
// rightは「常に条件を満たす」
// right - left == 1になるまで範囲を狭めていく．このときrightが条件を満たす最小のインデックスとなる

bool isOK(int index, int key) {
    if (key <= a[index]) {
        return true;
    } else {
        return false;
    }
}

// int binary_search(int key) {
//     int left = -1; // a[0]が条件を満たすかも知れないのであえて-1
//     int right = (int)a.size(); // a[a.size()-1]が条件を満たすかも知れないのであえて
//
//     while (1 < right - left) {
//         int mid = left + (right - left)/2;
//         if (isOK(mid, key)) {
//             right = mid; // [left] ng, ng, ng, ..., ng, ok, ok, ok, ..., ok [right]
//         } else {
//             left = mid;
//         }
//     }
//
//     return right; // leftは条件を満たさない最大のインデックス・rightは条件を満たす最小のインデックス
// }

// めぐる式二分探索
// 条件を満たす最小のインデックスを求める
// - leftは常に条件を満たさない
// - rightは常に条件を満たす
// - right - left == 1になるまで範囲を狭めていって，rightが条件を満たす最小のインデックス
// 条件を満たす最大のインデックスを求める
// - leftは常に条件を満たす
// - rightは常に条件を満たさない
// - right - left == 1になるまで範囲を狭めていって，leftが条件を満たす最大のインデックス
//
// これらを統一的に書けるのがめぐる式二分探索

int binary_search(int key) {

    // ここの初期値の与え方でいろんな探索が可能
    // 今回は条件を満たす最小のインデックスを返すパターン
    int NG = -1;
    int OK = (int)a.size();

    // 初期値をこっちに設定すると，条件を満たす最大のインデックスを返すことになる
    // int NG = (int)a.size();
    // int OK = -1;

    // ここのループはいじらなくて良くなる
    while (1 < abs(OK - NG)) {
        int mid = (OK + NG)/2;
        if (isOK(mid, key)) {
            OK = mid;
        } else {
            NG = mid;
        }
    }
    return OK;
}

int main() {
    cout << binary_search(51) << endl;
    return 0;
}