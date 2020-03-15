#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
#define SENTINEL 1000000005

struct card {
    char suit;
    int value;
};
using card = struct card;

card L[MAX / 2 + 2], R[MAX / 2 + 2];

// A[left, mid) と A[mid, right) をマージする
void merge(card A[], int n, int left, int mid, int right) {
    int nl = mid - left;
    int nr = right - mid;
    for (int i = 0; i < nl; i++) L[i] = A[left + i];
    for (int i = 0; i < nr; i++) R[i] = A[mid + i];
    L[nl].value = SENTINEL;
    R[nr].value = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i].value <= R[j].value) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

// 長さnの配列AのA[left, right)をソートする
void merge_sort(card A[], int n, int left, int right) {
    int mid;
    if (left + 1 < right) {
        mid = (left + right) / 2;
        merge_sort(A, n, left, mid);
        merge_sort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

// 長さnの配列AのA[p, r]を「A[r]以下の部分」と「A[r]より大きい部分」に分割する
int partition(card A[], int n, int p, int r) {
    card x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j].value <= x.value) {
            i++;
            card t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    card t = A[i + 1];
    A[i + 1] = A[r];
    A[r] = t;
    return i + 1;
}

// 長さnの配列AのA[p, r]をソートする
void quick_sort(card A[], int n, int p, int r) {
    if (p < r) {
        int q = partition(A, n, p, r);
        quick_sort(A, n, p, q-1);
        quick_sort(A, n, q, r);
    }
}

int main() {
    int n; cin >> n;
    card A[MAX], B[MAX];
    int stable = 1;
    for (int i = 0; i < n; i++) {
        char c; cin >> c; A[i].suit = B[i].suit = c;
        int v; cin >> v; A[i].value = B[i].value = v;
    }
    merge_sort(A, n, 0, n);
    quick_sort(B, n, 0, n-1);
    for (int i = 0; i < n; i++) {
        if (A[i].suit != B[i].suit) stable = 0;
    }
    if (stable) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << B[i].suit << " " << B[i].value << endl;
    }
    return 0;
}