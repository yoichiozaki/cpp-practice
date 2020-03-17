#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
#define NIL -1

struct node {
    int parent, left, right;
};
using node = struct node;

node Tree[MAX];
int Depth[MAX], Height[MAX];

void set_depth(int n, int d) {
    if (n == NIL) {
        return;
    }
    Depth[n] = d; // ノードnの深さをdに設定
    set_depth(Tree[n].left, d + 1);
    set_depth(Tree[n].right, d + 1);
}

int set_height(int n) {
    int hl = 0, hr = 0;
    if (Tree[n].left != NIL) {
        hl = set_height(Tree[n].left) + 1;
    }
    if (Tree[n].right != NIL) {
        hr = set_height(Tree[n].right) + 1;
    }
    return Height[n] = max(hl, hr);
}

int get_sibling(int n) {
    if (Tree[n].parent == NIL) {
        return NIL;
    }
    if (Tree[Tree[n].parent].left != n && Tree[Tree[n].parent].left != NIL) {
        return Tree[Tree[n].parent].left;
    }
    if (Tree[Tree[n].parent].right != n && Tree[Tree[n].parent].right != NIL) {
        return Tree[Tree[n].parent].right;
    }
    return NIL;
}

void print_node(int n) {
    cout << "node " << n << ": ";
    cout << "parent = " << Tree[n].parent << ", ";
    cout << "sibling = " << get_sibling(n) << ", ";
    int degree = 0;
    if (Tree[n].left != NIL) degree++;
    if (Tree[n].right != NIL) degree++;
    cout << "degree = " << degree << ", ";
    cout << "depth = " << Depth[n] << ", ";
    cout << "height = " << Height[n] << ", ";
    if (Tree[n].parent == NIL) {
        cout << "root";
    } else if (Tree[n].left == NIL && Tree[n].right == NIL) {
        cout << "leaf";
    } else {
        cout << "internal node";
    }
    cout << endl;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        Tree[i].parent = NIL;
        Depth[i] = 0;
        Height[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int v, l, r; cin >> v >> l >> r;
        Tree[v].left = l;
        Tree[v].right = r;
        if (l != NIL) Tree[l].parent = v;
        if (r != NIL) Tree[r].parent = v;
    }

    int root = 0;
    for (int i = 0; i < n; i++) {
        if (Tree[i].parent == NIL) {
            root = i;
        }
    }

    set_depth(root, 0);
    set_height(root);

    for (int i = 0; i < n; i++) {
        print_node(i);
    }
    return 0;
}