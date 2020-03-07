#include <bits/stdc++.h>
using namespace std;

// 与えられるグラフはN頂点の連結な無向グラフ（すでにM本の辺が張られている）
// 命題: 頂点sと頂点t間に奇数長のパスが存在しているならば，頂点sと頂点tを直接結ぶ辺が張られている
// 証明: 頂点sと頂点tの間に存在する奇数長のパスの長さをkとし，そのパス上に存在するi番目の頂点をv_iとする．
//      このときv_0 = s, v_k = tである．k = 1のとき，すでにs-t間に辺が張られている．k >= 3のとき，v_(k-3)とv_kの間に
//      辺を張ることができるので長さk-2の奇数長パスを新たに作成することができる．これを繰り返すことで長さ3の奇数長パスを得られ，
//      k = 3となったときs-tを直接結ぶ辺が張られることになる．よって命題は正しい．
// 頂点間に奇数長のパスが存在するかどうかはグラフが二部グラフであるかによって異なる．
// 1) グラフが二部グラフでないとき，そのグラフには奇数長のサイクルが存在する．ここでvを奇サイクル上の頂点であるとする．
//    与えられるグラフは連結であるため，任意の頂点の組(s, t)に対してs -> v -> tという順で頂点を訪れるパスが必ず存在する．
//    もしそのパスの長さが偶数だった場合，頂点vを訪問したときに余計に奇サイクル回ることでそのパスの長さを奇数にすることが可能である．
//    よって，任意の2頂点間に奇数長のパスが存在することになるので追加できる辺の本数はN(N-1)/2 - M
// 2) グラフが二部グラフのとき，全頂点を同じ色が隣り合うことのないように黒・白で塗り分けることができる．
//    任意の黒の頂点bと白の頂点wを取り上げると，与えられるグラフは連結なので，bとwの間にはパスが存在し，その長さは明らかに奇数となる．
//    一方で，同じ色の頂点間には辺が張られることはない．よって黒の頂点の個数をB，白の頂点の個数をWとすればBW-M本だけ辺を追加できることになる．

using Graph = vector<vector<int>>;

vector<int> color; // color[i] = 1: 黒確定/ 0: 白確定/ -1:未訪問
bool dfs(const Graph &G, int v, int current_color = 0) {
    color[v] = current_color;
    for (auto w : G[v]) {
        // 隣接頂点の色がすでに確定している場合
        if (color[w] != -1) {
            if (color[w] == current_color) {
                return false; // 同じ色が隣接してはいけない
            } else {
                continue;
            }
        }
        // 隣接頂点に反対の色をアサインして再帰的に探索し，一度でもfalseが返ってきたらダメ
        if (!dfs(G, w, 1 - current_color)) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    color.assign(N, -1);
    bool is_bipartite = true;
    for (int v = 0; v < N; v++) {
        if (color[v] != -1) { // vが訪問済みだったらスルー: 連結でないグラフを考慮
            continue;
        }
        if (!dfs(G, v)) {
            is_bipartite = false;
        }
    }
    if (is_bipartite) {
        int B = 0, W = 0;
        for (int v = 0; v < N; v++) {
            if (color[v] == 0) {
                W++;
            } else if (color[v] == 1) {
                B++;
            }
        }
        cout << W*B - M << endl;
    } else {
        cout << N*(N-1)/2 - M << endl;
    }
    return 0;
}