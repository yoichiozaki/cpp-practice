#include <bits/stdc++.h>
using namespace std;

struct node {
    int key;
    node *parent, *left, *right;
};
using node = struct node;

// 挿入したい頂点zを入れる位置を，木の根を始点として探していく
// xを「zを入れる位置辺数」，yを「xの直接の親」としてxがNILになるまで木を降りていく

node *root, *NIL;

void insert(int key) {
    node *x = root, *y = NIL, *z;
    z = (node *)malloc(sizeof(node));
    z->key = key;
    z->left = NIL;
    z->right = NIL;
    while (x != NIL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == NIL) { // 木がまだ存在していない
        root = z;
    } else {
        if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }
}

node* find(node *n, int key) {
    while (n != NIL && n->key != key) {
        if (n->key < key) {
            n = n->right;
        } else {
            n = n->left;
        }
    }
    return n;
}

void print_inorder(node *n) {
    if (n == NIL) return;
    print_inorder(n->left);
    cout << " " << n->key;
    print_inorder(n->right);
    return;
}

void print_preorder(node *n) {
    if (n == NIL) return;
    cout << " " << n->key;
    print_preorder(n->left);
    print_preorder(n->right);
    return;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "insert") {
            int key; cin >> key;
            insert(key);
        } else if (s == "print") {
            print_inorder(root);
            cout << endl;
            print_preorder(root);
            cout << endl;
        } else if (s == "find") {
            int key; cin >> key;
            node *res = find(root, key);
            if (res == NIL) cout << "no" << endl;
             else cout << "yes" << endl;
        }
    }
    return 0;
}