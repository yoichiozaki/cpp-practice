#include <bits/stdc++.h>
using namespace std;

// スタック・キュー: データの到着順に従って追加・削除を行う
// ヒープ: データが持つあるkeyを基準にして追加・削除を行う
//     - 特に，データが持つkeyを基準として優先度の高い方から取り出すものを「優先度付きキュー」と呼ぶ

// max_heapify(int i): A[i]を根とする部分完全2分木をmax-heapにする

#define MAX 2000000

int H, A[MAX+1];

void max_heapify(int i) {
    int l, r, largest;
    l = 2*i;
    r = 2*i + 1;

    if (l <= H && A[l] > A[i]) largest = l;
    else largest = i;
    if (r <= H && A[r] > A[largest]) largest = r;

    if (largest != i) {
        swap(A[i], A[largest]);
        max_heapify(largest);
    }
}

int main() {
    cin >> H;
    for (int i = 1; i <= H; i++) cin >> A[i];
    for (int i = H/2; 1 <= i; i--) max_heapify(i);
    for (int i = 1; i <= H; i++) {
        cout << " " << A[i];
    }
    cout << endl;
    return 0;
}