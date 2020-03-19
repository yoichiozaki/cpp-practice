#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int parent(int i) {
    return i/2;
}

int left_child(int i) {
    return 2*i;
}

int right_child(int i) {
    return 2*i + 1;
}

int main() {
    int H, A[MAX+1];
    cin >> H;
    for (int i = 1; i <= H; i++) cin >> A[i];
    for (int i = 1; i <= H; i++) {
        cout << "node " << i << ": key = " << A[i] << ", ";
        if (parent(i) >= 1) cout << "parent key = " << A[parent(i)] << ", ";
        if (left_child(i) <= H) cout << "left key = " << A[left_child(i)] << ", ";
        if (right_child(i) <= H) cout << "right key = " << A[right_child(i)] << ", ";
        cout << endl;
    }
    return 0;
}