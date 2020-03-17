#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
#define NIL -1

struct Node {
    int parent, left_child, right_sibling;
};
using node = struct Node;

node Tree[MAX];
int Depth[MAX];

void print_node(int u) {
    cout << "node " << u << ": ";
    cout << "parent = " << Tree[u].parent << ", ";
    cout << "depth = " << Depth[u] << ", ";

    if (Tree[u].parent == NIL) {
        cout << "root, ";
    } else if (Tree[u].left_child == NIL) {
        cout << "leaf, ";
    } else {
        cout << "internal node, ";
    }

    cout << "[";

    for (int i = 0, child = Tree[u].left_child; child != NIL; i++, child = Tree[child].right_sibling) {
        if (i) {
            cout << ", ";
        }
        cout << child;
    }
    cout << "]" << endl;
}

int calc_depth(int u, int p) {
    Depth[u] = p; // uの深さをpに設定
    if (Tree[u].right_sibling != NIL) calc_depth(Tree[u].right_sibling, p); // 兄弟みんな深さpに設定
    if (Tree[u].left_child != NIL) calc_depth(Tree[u].left_child, p+1); // 子供を1つ深くする
    return p;
}

int main() {
    int r, l;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        Tree[i].parent = NIL;
        Tree[i].left_child = NIL;
        Tree[i].right_sibling = NIL;
    }
    for (int i = 0; i < n; i++) {
        int v, d; cin >> v >> d;
        for (int j = 0; j < d; j++) {
            int c; cin >> c;
            if (j == 0) Tree[v].left_child = c;
            else Tree[l].right_sibling = c;
            l = c;
            Tree[c].parent = v;
        }
    }
    for (int i = 0; i < n; i++) {
        if (Tree[i].parent == NIL) {
            r = i;
        }
    }
    calc_depth(r, 0);
    for (int i = 0; i < n; i++) {
        print_node(i);
    }
    return 0;
}