#include <bits/stdc++.h>
using namespace std;

#define MAX 200000
#define SENTINEL 2000000000
using ll = long long;

int L[MAX / 2 + 2], R[MAX / 2 + 2];

ll merge(int A[], int n, int left, int mid, int right) {
    ll cnt = 0;
    int nl = mid - left;
    int nr = right - mid;
    for (int i = 0; i < nl; i++) L[i] = A[left + i];
    for (int i = 0; i < nr; i++) R[i] = A[mid + i];
    L[nl] = SENTINEL;
    R[nr] = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
            cnt += nl - i;
        }
    }
    return cnt;
}

ll merge_sort(int A[], int n, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        ll v1 = merge_sort(A, n, left, mid);
        ll v2 = merge_sort(A, n, mid, right);
        ll v3 = merge(A, n, left, mid, right);
        return v1 + v2 + v3;
    } else {
        return 0;
    }
}

int main() {
    int A[MAX], n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    ll ans = merge_sort(A, n, 0, n);
    cout << ans << endl;
    return 0;
}