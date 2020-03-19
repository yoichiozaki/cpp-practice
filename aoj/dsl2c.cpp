#include <bits/stdc++.h>
using namespace std;

// 座標を二分木に格納して管理する

class Node {
public:
    int location; // 座標組のリストPにおけるインデックス
    int parent, left, right;
    Node() {}
};

class Point {
public:
    int id, x, y;
    Point() {}
    Point(int id, int x, int y): id(id), x(x), y(y) {}
    bool operator < (const Point &p) const {
        return id < p.id;
    }
    void print() {
        printf("%d\n", id);
    }
};

const int MAX = 1000000;
const int NIL = -1;

int N;
Point P[MAX];
Node Tree[MAX];
int np; // 座標の木におけるpreorder順での位置

bool less_on_x(const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}

bool less_on_y(const Point &p1, const Point &p2) {
    return p1.y < p2.y;
}

// P[left, right)を二分木に格納する．出来上がる木の根となる座標のPにおけるインデックスを返す
int make_KD_tree(int left, int right, int depth) {
    if (!(left < right)) return NIL;
    int mid = (left + right) / 2;
    int t = np++;

    // 二次元座標を縦に切って横に切って...
    if (depth % 2 == 0) {
        sort(P+left, P+right, less_on_x);
    } else {
        sort(P+left, P+right, less_on_y);
    }

    Tree[t].location = mid;
    Tree[t].left = make_KD_tree(left, mid, depth+1);
    Tree[t].right = make_KD_tree(mid+1, right, depth+1);

    return t;
}

// vを根とする部分木内でsx <= x <= tx, sy <= y < tyを満たす点(x, y)をansに格納する
void find(int v, int sx, int tx, int sy, int ty, int depth, vector<Point> &ans) {
    int x = P[Tree[v].location].x;
    int y = P[Tree[v].location].y;

    if (sx <= x && x <= tx && sy <= y && y <= ty) {
        ans.push_back(P[Tree[v].location]);
    }

    if (depth % 2 == 0) {
        if (Tree[v].left != NIL) {
            if (sx <= x) {
                find(Tree[v].left, sx, tx, sy, ty, depth+1, ans);
            }
        }
        if (Tree[v].right != NIL) {
            if (x <= tx) {
                find(Tree[v].right, sx, tx, sy, ty, depth+1, ans);
            }
        }
    } else {
        if (Tree[v].left != NIL) {
            if (sy <= y) {
                find(Tree[v].left, sx, tx, sy, ty, depth+1, ans);
            }
        }
        if (Tree[v].right != NIL) {
            if (y <= ty) {
                find(Tree[v].right, sx, tx, sy, ty, depth+1, ans);
            }
        }
    }
}

int main() {
    int x, y;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        P[i] = Point(i, x, y);
        Tree[i].parent = NIL;
        Tree[i].left = NIL;
        Tree[i].right = NIL;
    }

    np = 0;

    int root = make_KD_tree(0, N, 0);

    int q;
    scanf("%d", &q);
    int sx, tx, sy, ty;
    vector<Point> ans;
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
        ans.clear();
        find(root, sx, tx, sy, ty, 0, ans);
        sort(ans.begin(), ans.end());
        for (int j = 0; j < ans.size(); j++) {
            ans[j].print();
        }
        printf("\n");
    }
    return 0;
}