#include <bits/stdc++.h>
using namespace std;

// keyの大きいものを優先する優先度付きキューはmaxヒープを用いて実現できる

#define MAX 2000000
#define INF (1<<30)

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

int pop() {
    int maxv;
    if (H < 1) return -INF;
    maxv = A[1];
    A[1] = A[H--];
    max_heapify(1);
    return maxv;
}

void increase_key(int i, int key) {
    if (key < A[i]) return;
    A[i] = key;
    while (1 < i && A[i/2] < A[i]) {
        swap(A[i], A[i/2]);
        i = i/2;
    }
}

void push(int key) {
    H++;
    A[H] = -INF;
    increase_key(H, key);
}

int main() {
    int key;
    string command;
    while (cin >> command) {
        if (command == "insert") {
            int key; cin >> key;
            push(key);
        } else if (command == "extract") {
            cout << pop() << endl;
        } else if (command == "end") {
            break;
        }
    }
    return 0;
}