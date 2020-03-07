#include <bits/stdc++.h>
using namespace std;

// REF: https://qiita.com/drken/items/4a7869c5e304883f539b
// REF: https://qiita.com/drken/items/a803d4fc4a727e02f7ba

// # グラフ探索の動機
// - コンピュータは今やとても身近な存在になった
// - コンピュータの用途として「探索」は基本的かつ重要
// - 探索とは「与えられた対象の中から，目的に合うものを見つけ出したり最良のものを見つけ出したり，条件を満たすものを列挙すること」
// - 世の中の様々な問題は，探索によって考えられる場合をすべて調べ尽くすことによって原理的には解決可能なものが多い
// - しかし実際問題として，あり得る場合が膨大すぎて全部探索する手法の適用が困難なことも多い
// - そこで「どうしたらすべての場合を調べ尽くせるか」を考えることは重要．これを考えることでときたい問題の構造に対する深い理解を得ることができ，結果的に高速なアルゴリズムの設計につながることも多い
// - 問題をグラフを用いて定式化するという手法は有効に働くことがある．
// # グラフとは
// - グラフは事物の関係性のみを抽象化して頂点と辺で表現したもの
// - グラフ理論の用語については省略
// # 計算機上でのグラフの表現の仕方
// - 計算機上でのグラフの表現は「隣接リスト表現」と「隣接行列表現」に大別される
// - 隣接行列は頂点数に対して辺数が多いような密度の高いグラフでは効率的な表現ができる
// - 隣接リストは頂点数に足しいて辺数がそこまで多くない場合では効率的
// - 以下では「隣接リスト表現」を対象とする
//
// using Graph = vector<vector<int>>; // Graph型を型エイリアスで定義
// Graph G;

// グラフの入力を受け取る
// using Graph = vector<vector<int>>;
//
// int main() {
//     // N: 頂点数
//     // M: 辺数
//     int N, M; cin >> N >> M;
//
//     Graph G(N);
//     for (int i = 0; i < M; i++) {
//         int a, b; cin >> a >> b;
//         G[a].push_back(b);
//         // 無向グラフのときは以下も追加
//         // G[b].push_back(a);
//     }
//     return 0;
// }

// 重み付きグラフ
// struct Edge {
//     int to;
//     int weight;
//     Edge(int t, int w) : to(t), weight(w) { } // コンストラクタ
// };
// using Graph = vector<vector<Edge>>;
//
// int main() {
//     int N, M; cin >> N >> M;
//
//     Graph G(N);
//     for (int i = 0; i < M; i++) {
//         int from, to, weight;
//         cin >> from >> to >> weight;
//         G[from].push_back(Edge(to, weight));
//     }
//     return 0;
// }

// Boostライブラリもあるよ

// グラフに対する深さ優先探索と幅優先探索
// - 探索できるところまで突き進んで，行き止まりまで到達したら戻るを繰り返すの深さ優先探索
// - 探索できるノードは先に探索してしまいながら探索するのが幅優先探索
// - 深さ優先と幅優先の本質的な違いは「ためたノードをどのタイミングで探索するか」
//
// bool seen[N]: N個の頂点のそれぞれに対してその頂点を検知済みかどうかを保持する配列
// int todo[]: 検知したがまだ訪問済みではない頂点の集合（保留中の頂点集合）
// 1. seen全体をfalseに・todoを空に初期化
// 2. seen[start] = true・todoに頂点startを追加
// 3.  while(todo.isEmpty()) {
// 4.      todoから1つ頂点を取り出してvとする; // ここでの頂点vの取り出し方でBFS/DFSの違いが出る）
// 5.      for (w : vの隣接頂点) {
// 6.          if (seen[w] = true) {
// 7.              continue; // 検知済みなので何もしない
// 8.          } else {
// 9.              seen[w] = true; todoにwを追加する;
// 10.         }
// 11.     }
// 12. }
//
// todoから頂点を取り出すポリシーとして
// - 最後に追加したものから先に取る（LIFO）だと深さ優先探索 => stackを用いてDFSは実装できる
// - 最初に追加したものから先に取る（FIFO）だと幅優先探索 => queueを用いてBFSは実装できる

// 木の探索順
// - 木は「グラフの特殊バージョン」である．この意識を持っていると整理が捗る．
// - 木の定義は「サイクルを持たないかつ連結であるようなグラフ」のこと．
// - 特に木の中でも特定の一つの頂点を特別扱いして「根 root」と呼ぶことがある．そのような木を根付き木 rooted treeと呼ぶ
// - 木はグラフの一種なので，木に対しても深さ優先・幅優先探索が実行できる
// - 根付き木であればrootを始点とするのが自然
// - 木に対する幅優先探索は，頂点をrootから見た距離でレベル分けした用に探索することになる

// DFSの再帰関数を用いた実装
// - DFSはstackを用いて実装できるけど，再帰関数を用いても実装できる
// - 複雑な処理を行おうとなると再帰で書いたほうがいい場面が多い
//

// using Graph = vector<vector<int>>;
//
// vector<bool> seen;
// void DFS(const Graph &G, int v) {
//     seen[v] = true; // 頂点vを検知済みに
//
//     for (auto w : G[v]) {
//         if (seen[w]) {
//             continue;
//         } else {
//             DFS(G, w);
//         }
//     }
// }
//
// int main() {
//     int N, M; cin >> N >> M;
//
//     Graph G(N);
//     for (int i = 0; i < M; i++) {
//         int a, b; cin >> a >> b;
//         G[a].push_back(b);
//         G[b].push_back(a);
//     }
//
//     seen.assign(N, false);
//     DFS(G, 0); // 頂点0を始点としてDFS
// }

// DFSの探索順序について考える
// - 木に対するDFSの各頂点の訪問順序を考える（一般のグラフに対しても深さ優先探索木を考えることで結局木と同様に考えられる）
// - 「行きがけ順」：根から初めて訪問した頂点の順序で順位をつけたもの＝DFS()に入った直後の順位
// - 「帰りがけ順」：最後に訪問した頂点の順序で順位をつけたもの＝DFS()を抜ける直前の順位
// - 「タイムスタンプ」：行きがけ順と帰りがけ順を統一的に扱うもの．t = 0から始まって一秒ごとにDFSに従って探索していくときに「最初に訪問した時刻/最後に訪問した時刻」をタイムスタンプという

// using Graph = vector<int<int>>;
//
// vector<bool> seen;
// vector<int> first_order;
// vector<int> last_order;
//
// void DFS(const Graph &G, int v, int &first_ptr, int &last_ptr) {
//     first_order[v] = first_ptr++;
//
//     seen[v] = true;
//     for (auto w : G[v]) {
//         if (seen[w]) {
//             continue;
//         } else {
//             DFS(G, w, first_ptr, last_ptr);
//         }
//     }
//
//     last_order[v] = last_ptr++;
// }
//
// int main() {
//     int N, M; cin >> N >> M;
//
//     Graph G(N);
//     for (int i = 0; i < M; i++) {
//         int a, b; cin >> a >> b;
//         G[a].push_back(b);
//         G[b].push_back(a);
//     }
//
//     seen.assign(N, false);
//     first_order.resize(N);
//     last_order.resize(N);
//     int first_ptr = 0, last_ptr = 0;
//     DFS(Gm 0, first_ptr, last_ptr);
//
//     for (int i = 0; i < N; i++) {
//         cout << i << ": " << first_order[i] << ", " << last_order[i] << endl;
//     }
//
//     return 0;
// }

// タイムスタンプ
// void DFS(const Graph &G, int v, int &ptr) {
//     first_order[v] = ptr++;
//
//     seen[v] = true;
//     for (auto w : G[v]) {
//         if (seen[w]) {
//             continue;
//         } else {
//             DFS(G, w, ptr);
//         }
//     }
//
//     last_order[v] = ptr++;
// }

// DFSの計算量
// - 頂点数N，辺数Mのグラフに対して
// - 訪問していない頂点については1つ選んでDFSを実行するので，DFS全体においてすべての頂点を一通り調べることになるためO(n)
// - 全ての辺に対してたかだか一回しか通過しない（seen[w] = trueならcontinueしている）のでO(m)
// - よってDFS全体としての計算量はO(n+m)
// - これは「グラフの入力を受け取るのと同じ計算量でDFSの探索が可能である」ということを意味する

// グラフ探索問題のさまざま
// 到達可能性問題：頂点sから頂点tにたどり着けるか＝sを始点とするDFSをすれば良い
//
// using Graph = vector<vector<int>>;
//
// vector<bool> seen;
// void DFS(const Graph &G, int v) {
//     seen[v] = true;
//
//     for (auto w : G[v]) {
//         if (seen[w]) {
//             continue;
//         } else {
//             DFS(G, w);
//         }
//     }
// }
//
// int main() {
//     int N, M, s, t; cin >> N >> M >> s >> t;
//
//     Graph G(N);
//     for (int i = 0; i < M; i++) {
//         int a, b; cin >> a >> b;
//         G[a].push_back(b);
//     }
//
//     seen.assign(N, false);
//     DFS(G, s);
//
//     if (seen[t]) {
//         cout << "Yes" << endl;
//     } else {
//         cout << "No" << endl;
//     }
// }

// グリッドグラフに対する到達可能性問題
// - グリッドグラフとは以下のようなグラフ
//
// 10 10
// s.........
// #########.
// #.......#.
// #..####.#.
// ##....#.#.
// #####.#.#.
// g.#.#.#.#.
// #.#.#.#.#.
// #.#.#.#.#.
// #.....#...
//

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};
//
// int H, W;
// vector<string> field;
//
// bool seen[510][510]; // seen[i][j] = (i, j)が検知済みか
// void DFS(int h, int w) {
//     seen[h][w] = true;
//
//     for (int i = 0; i < 4; i++) {
//         int nh = h + dx[i];
//         int nw = w + dy[i];
//
//         if (nh < 0 || H <= nh || nw < 0 || W <= nw) {
//             continue; // 場外なので進めない
//         }
//         if (field[nh][nw] == '#') {
//             continue; // 壁なので進めない
//         }
//
//         if (seen[nh][nw]) {
//             continue; // 検知済みなのでスルー
//         }
//
//         DFS(nh, nw);
//     }
// }
//
// int main() {
//     cin >> H >> W;
//     field.resize(H);
//     for (int i = 0; i < H; i++) {
//         cin >> field[i];
//     }
//
//     int sh, sw, gh, gw;
//     for (int i = 0; i < H; i++) {
//         for (int j = 0; j < W; j++) {
//             if (field[i][j] == 's') {
//                 sh = i;
//                 sw = j;
//             }
//             if (field[i][j] == 'g') {
//                 gh = i;
//                 gw = j;
//             }
//         }
//     }
//
//     memset(seen, 0, sizeof(seen));
//
//     DFS(sh, sw);
//
//     if (seen[gh][gw]) {
//         cout << "Yes" << endl;
//     } else {
//         cout << "No" << endl;
//     }
// }

// 連結成分の個数をカウントする問題
// - 「未探索の頂点を1つ選んでそれを始点としたDFSを行う」を未訪問の頂点が存在しなくなるまで繰り返す
// - Union-Find treeを使ってもいいしBFSでも解ける

// using Graph = vector<vector<int>>;
//
// vector<bool> seen;
// void DFS(const Graph &G, int v) {
//     seen[v] = true;
//     for (auto w : G[v]) {
//         if (seen[w]) {
//             continue;
//         }
//         DFS(G, w);
//     }
// }
//
// int main() {
//     int N, M; cin >> N >> M;
//
//     Graph G(N);
//     for (int i = 0; i < M; i++) {
//         int a, b; cin >> a >> b;
//         G[a].push_back(b);
//         G[b].push_back(a);
//     }
//
//     int count = 0;
//     seen.assign(N, false);
//     for (int v = 0; v < N; v++) {
//         if (seen[v]) {
//             continue; // 探索済みなのでスルー
//         } else {
//             DFS(G, v); // vが未探索ならvを始点としてDFS
//             count++;
//         }
//     }
//
//     cout << count << endl;
// }

// グリッドグラフに対する連結成分のカウント
// #include <bits/stdc++.h>
// using namespace std;
//
// int H, W;
// vector<vector<int>> field;
//
// void dfs(int h, int w) {
//     field[h][w] = 0; // 探索済みの陸地は海にしてしまう
//
//     for (int dh = -1; dh <= 1; dh++) {
//         for (int dw = -1; dw <= 1; dw++) {
//             int nh = h + dh, nw = w + dw;
//
//             if (nh < 0 || H <= nh || nw < 0 || W <= nw) {
//                 continue; // 場外なのでスルー
//             }
//             if (field[nh][nw] == 0) {
//                 continue; // 海なのでスルー
//             }
//
//             dfs(nh, nw);
//         }
//     }
// }
//
// int main() {
//     while (cin >> W >> H) {
//         if (H == 0 || W == 0) {
//             break;
//         }
//         field.assign(H, vector<int>(W, 0));
//         for (int h = 0; h < H; h++) {
//             for (int w = 0; w < W; w++) {
//                 cin >> field[h][w];
//             }
//         }
//
//         int count = 0;
//         for (int h = 0; h < H; h++) {
//             for (int w = 0; w < W; w++) {
//                 if (field[h][w] == 0) {
//                     continue;
//                 }
//                 dfs(h, w);
//                 count++;
//             }
//         }
//
//         cout << count << endl;
//     }
//     return 0;
// }
