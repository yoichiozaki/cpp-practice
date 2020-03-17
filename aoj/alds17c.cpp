#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
#define NIL -1

struct Node {
    int parent, left, right;
};
using node = struct Node;

node Tree[MAX];

// parent -> left -> right
void preorder(int n) {
    if (n == NIL) return;
    cout << " " << n;
    preorder(Tree[n].left);
    preorder(Tree[n].right);
    return;
}

// left -> parent -> right
void inorder(int n) {
    if (n == NIL) return;
    inorder(Tree[n].left);
    cout << " " << n;
    inorder(Tree[n].right);
    return;
}

// left -> right > parent
void postorder(int n) {
    if (n == NIL) return;
    postorder(Tree[n].left);
    postorder(Tree[n].right);
    cout << " " << n;
    return;
}

int main() {
    int root = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++) Tree[i].parent = NIL;
    for (int i = 0; i < n; i++) {
        int p, l, r; cin >> p >> l >> r;
        Tree[p].left = l;
        Tree[p].right = r;
        if (l != NIL) Tree[l].parent = p;
        if (r != NIL) Tree[r].parent = p;
    }
    for (int i = 0; i < n; i++) {
        if (Tree[i].parent == NIL) {
            root = i;
        }
    }
    cout << "Preorder" << endl;
    preorder(root);
    cout << endl;
    cout << "Inorder" << endl;
    inorder(root);
    cout << endl;
    cout << "Postorder" << endl;
    postorder(root);
    cout << endl;
    return 0;
}