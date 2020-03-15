#include <bits/stdc++.h>
using namespace std;

int selection_sort(vector<int> &a, int n) {
    int sw = 0;
    for (int i = 0; i < n-1; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[minj]) minj = j;
        }
        swap(a[i], a[minj]);
        if (i != minj) sw++;
    }
    return sw;
}

int main() {
    int N; cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) cin >> A[i];
    int sw = selection_sort(A, N);
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
    return 0;
}