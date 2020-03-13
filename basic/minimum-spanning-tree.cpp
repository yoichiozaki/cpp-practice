#include <bits/stdc++.h>
using namespace std;

// 最小全域木
// - 全域木: spanning tree
//     - 連結グラフのすべての頂点とそのグラフを構成する辺の一部分のみで構成される木
//     - つまり，連結グラフから適当な辺を取り除いていき，閉路を持たない木の形をしたものが全域木
//     - グラフの各辺に重みがある場合，重みの総和が最小となるように辺を選んで作った全域機を最小全域木（minimum spanning tree）という
// - 最小全域木を求めるアルゴリズムはクラスカル法（Kruskal）とプリム法（Prim）が有名
//
// クラスカル法
// 1. グラフの各頂点がそれぞれ木に属するように，森，つまり木の集合Fを生成する: つまり，「頂点1個のみからなる木」が頂点の個数だけ存在する
// 2. グラフのすべての辺を含む集合Eを生成する
// 3. 辺集合Eが空集合になるまで以下を繰り返す
//     3.1. 辺集合Eから重みが最小の辺eを取り出し，Eから削除する
//     3.2. 辺eを構成する2頂点u, vについて，それぞれが別の木に属しているなら，辺eを森Fに加え，u，vが属している2つの木を統合して一つの木にまとめる
// 4. 最終的に森Fが求めたい最小全域木になる
//
// - 2頂点u，vが別の木に属しているのかを判定するのはUnion-Findを使う
//
// プリム法
// 1. 空集合V，Eを用意する
// 2. グラフから任意の頂点を一つ選びVに加える
// 3. Vがグラフのすべての頂点を含むまで以下を繰り返す
//     3.1. Vに含まれる頂点uと含まれない頂点vを結ぶ重みが最小の辺(u, v)を選択してEに加える．
//     3.2. vをVに加える
// 4. 最終的にグラフ（V, E）が求めたい最小全域木になる

// http://acm.pku.edu.cn/JudgeOnline/problem?id=2031
// 級の形をした各宇宙ステーションの座標と半径が与えられる．これらの宇宙ステーション間に通路を建設し，全宇宙ステーションを連結させたい．このとき，必要な通路長の最小値を求めよ

// クラスカル法による解答
// class DisjointSet { // 2頂点u，vが同じ木に属しているかを判別するためのデータ構造
// private:
//     vector<int> p;
//
// public:
//     DisjointSet(int size) : p(size, -1) { }
//
//     bool unite_set(int x, int y) {
//         x = root(x);
//         y = root(y);
//
//         if (x != y) {
//             if (y < x) { swap(x, y); }
//             p[x] += p[y];
//             p[y] = x;
//         }
//         return x != y;
//     }
//
// private:
//     int root(int x) {
//         return p[x] < 0 ? x : p[x] = root(p[x]);
//     }
// };
//
// struct corridor {
//     int a, b; // この通路が接続している宇宙ステーション
//     double len; // この通路の長さ
//     corridor(int a, int b, double len) : a(a), b(b), len(len) { }
//
//     bool operator <(const corridor& rhs) const {
//         if (len != rhs.len) { return len < rhs.len; }
//         if (a != rhs.a) { return a < rhs.a; }
//         return b < rhs.b;
//     }
// };
//
// double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
//     return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
// }
//
// int main() {
//     int n;
//     while (cin >> n && n) {
//         double x[100], y[100], z[100], r[100];
//         for (int i = 0; i < n; i++) {
//             cin >> x[i] >> y[i] >> z[i];
//         }
//         vector<corridor> cor;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 cor.push_back(corridor(i, j, max(0.0, dist(x[i], y[i], z[i], x[j], y[i], z[j]) - r[i] - r[j])));
//             }
//         }
//         sort(cor.begin(), cor.end());
//
//         DisjointSet ds(n);
//         double ans = 0;
//         int count = 0;
//
//         for (auto iter = cor.begin(); count < n-1; iter++) {
//             if (ds.unite_set(iter->a, iter->b)) {
//                 ans += iter->len;
//                 count++;
//             }
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }

// プリム法による解答
// double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
//     return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
// }
//
// int main() {
//     int n;
//     while (cin >> n && n) {
//         double x[100], y[100], z[100], r[100];
//         for (int i = 0; i < n; i++) {
//             cin >> x[i] >> y[1] >> z[i] >> r[i];
//         }
//
//         set<int> cell; // これまでに選択した宇宙ステーションの集合
//         double ans = 0;
//
//         multimap<double, int> corridor; // （通路の長さ, 通路のつながっている先）のmap．最終的にこのmapに含まれている辺の集合が最小全域木になる
//         corridor.insert(make_pair(0.0, 0));
//
//         while (cell.size() < n) { // cellに全頂点が含まれるまで繰り返す
//
//             // corridorに含まれる一番重みの小さい辺を取り出す
//             double len = corridor.begin()->first;
//             int c = corridor.begin()->second;
//             corridor.erase(corridor.begin());
//
//             // 選んだ辺がcorridorにすでに含まれる辺を構成する頂点とつながっているならスルー
//             if (!cell.insert(c).second) { continue; }
//             ans += len; // 選んだ辺がcorridorにすでに含まれている辺を構成する頂点とつながっていないので，その頂点は最小全域木に含まれる
//
//             // 新たに加えられた頂点につながる通路を，次のイテレーションで探索するためにcorridorに追加しておく
//             for (int i = 0; i < n; i++) {
//                 if (cell.find(i) == cell.end()) { // 加えられた頂点につながる頂点をこれまでに選択していなかった
//                     corridor.insert(make_pair(max(0.0, dist(x[i], y[i], z[i], x[c], y[c], z[c]) - r[i] - r[c]), i));
//                 }
//             }
//         }
//         cout << ans << endl;
//     }
// }