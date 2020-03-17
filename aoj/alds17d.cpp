#include <bits/stdc++.h>
using namespace std;

// 先行順巡回: parent -> left -> right
// 中間順巡回: left -> pearent -> right
// 後行順巡回: left -> right -> parent
// 中間順巡回では{ ...left... [parent] ...right... }に分けられる

vector<int> preorder, inorder, postorder;
int n, pos;

// postorderの[l, r]を復元する
void rec(int l, int r) {
    if (l >= r) return;

    // preorderから1つ取り出す
    int root = preorder[pos]; pos++;
    // { ...left... [parent] ...right... }
    int m = distance(inorder.begin(), find(inorder.begin(), inorder.end(), root));

    // postorderの順番にpostorderにpush_back
    rec(l, m); // left部分木をpostorderにpush_back
    rec(m+1, r); // right部分木をpostorderにpush_back
    postorder.push_back(root);
}

void solve() {
    pos = 0;
    rec(0, (int)preorder.size());
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << postorder[i];
    }
    cout << endl;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        preorder.push_back(k);
    }
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        inorder.push_back(k);
    }
    solve();
    return 0;
}