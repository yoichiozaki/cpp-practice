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

// 二部グラフ判定
// - 二部グラフとは「白頂点同士が辺で結ばれることなく，黒頂点同士が辺で結ばれることもないように全頂点を白・黒に塗り分けられるグラフ」のこと
// - DFSで与えられたグラフが二部グラフであるかを判定することができる
// - Union-FindでもBFSでも解ける
// - DFSの始点となる頂点の色を確定させると芋づる式に全頂点の色が決まっていくので同じ色どうしが隣り合わないかどうかを確認すれば良い
//
// using Graph = vector<vector<int>>;
//
// vector<int> color; // color[i] = 1: 黒確定/ 0: 白確定/ -1:未訪問
// bool dfs(const Graph &G, int v, int current_color = 0) {
//     color[v] = current_color;
//     for (auto w : G[v]) {
//         // 隣接頂点の色がすでに確定している場合
//         if (color[w] != -1) {
//             if (color[w] == current_color) {
//                 return false; // 同じ色が隣接してはいけない
//             } else {
//                 continue;
//             }
//         }
//         // 隣接頂点に反対の色をアサインして再帰的に探索し，一度でもfalseが返ってきたらダメ
//         if (!dfs(G, w, 1 - current_color)) {
//             return false;
//         }
//     }
//     return true;
// }
//
// int main() {
//     int N, M; cin >> N >> M;
//     Graph G(N);
//     for (int i = 0; i < M; i++) {
//         int a, b; cin >> a >> b;
//         G[a].push_back(b);
//         G[b].push_back(a);
//     }
//     color.assign(N, -1);
//     bool is_bipartite = true;
//     for (int v = 0; v < N; v++) {
//         if (color[v] != -1) { // vが訪問済みだったらスルー: 連結でないグラフを考慮
//             continue;
//         }
//         if (!dfs(G, v)) {
//             is_bipartite = false;
//         }
//     }
//     return 0;
// }

// 根のない木の走査
// - 木は「閉路がない連結なグラフ」でしなかいので，木には常に根があるというわけではない．
// - 与えられた木に対して，ある頂点を根として選んだときその木が根付き木になるかどうかを判別する問題を考える
// - 根候補として選んだ頂点からDFSしていって，全頂点を訪問できていればその頂点は根として採用できる
// - ある頂点vの隣接頂点wを順番に見ていくときに，wがvの親と等しいときwは必ず訪問済みであるはず

// using Graph = vector<vector<int>>;
//
// // v: 現在探索中の頂点
// // p: vの親頂点（pが根のときは-1）
// void dfs(const Graph &G, int v, int p) {
//     for (auto w : G[v]) {
//         if (w == p) {
//             continue; // pはvの親なので探索済み
//         }
//         dfs(G, w, v); // vはwの親
//     }
// }
//
// int main() {
//     int N; cin >> N;
//     Graph G(N);
//     for (int i = 0; i < N-1; i++) { // N頂点から成る木に含まれる辺はN-1本
//         int a, b; cin >> a >> b;
//         G[a].push_back(b);
//         G[b].push_back(a);
//     }
//     int root = 0;
//     dfs(G, root, -1);
//     return 0;
// }

// 木の深さ
// - dfsに引数として頂点vの深さdを与えてやれば良い
// // v: 現在探索中の頂点
// // p: vの親頂点（pが根のときは-1）
// // d: vの深さ
// void dfs(const Graph &G, int v, int p, int d) {
//     depth[v] = d;
//     for (auto w : G[v]) {
//         if (w == p) {
//             continue; // pはvの親なので探索済み
//         }
//         dfs(G, w, v, d+1); // vはwの親
//     }
// }

// 部分木のサイズ
// - 頂点vを根とする部分木のサイズ = Σ(vの子ノードcを根とする部分木のサイズ) + 1
// - 頂点vについての情報を求めるのにvの子ノードについての情報が求まっている必要があるような処理は「帰りがけ時に行う」
// - 子ノードの情報を用いて親ノードの情報を更新する＝木DP

// using Graph = vector<vector<int>>;
//
// vector<int> depth;
// vector<int> subtree_size;
// void dfs(const Graph &G, int v, int p, int d) {
//
//     // 行きがけ時に頂点の深さを更新
//     depth[v] = d;
//
//     for (auto w : G[v]) {
//         if (w == p) {
//             continue;
//         }
//         dfs(G, w, v, d+1);
//     }
//
//     // 帰りがけ時にsubtree_sizeを更新
//     subtree_size[v] = 1;
//     for (auto c : G[v]) {
//         if (c == p) {
//             continue;
//         }
//         subtree_size[v] += subtree_size[c];
//     }
// }
//
// int main() {
//     int N; cin >> N;
//     Graph G(N);
//     for (int i = 0; i < N-1; i++) {
//         int a, b; cin >> a >> b;
//         G[a].push_back(b);
//         G[b].push_back(a);
//     }
//     int root = 0;
//     depth.assign(N, 0);
//     subtree_size.assign(N, 0);
//     dfs(G, root, -1, 0);
//     return 0;
// }

// 行きがけ時になにかする <- 親ノードの情報を子ノードに配る
// 帰りがけ時になにかする <- 子ノードの情報を親ノードの集める

// トポロジカルソート
// - サイクルのない有向グラフDAGに対して，頂点を辺の向きに装用に一列に並べること
// - 「DAGであること」と「トポロジカルソートができるグラフであること」は同値
// - グラフに対するトポロジカルソートは「再帰関数から抜ける順番の逆」で求められる

// using Graph = vector<vector<int>>;
//
// void dfs(const Graph &G, int v, vector<bool> &seen, vector<int> &order) {
//     seen[v] = true;
//     for (auto w : G[v]) {
//         if (seen[w]) {
//             continue;
//         }
//         dfs(G, w, seen, order);
//     }
//     order.push_back(v); // 再帰関数を抜けるタイミングで自分自身を登録
// }
//
// int main() {
//     int N, M; cin >> N >> M;
//     Graph G(N);
//     for (int i = 0; i < M; i++) {
//         int a, b; cin >> a >> b;
//         G[a].push_back(b);
//     }
//     vector<bool> seen(N, 0);
//     vector<int> order;
//     for (int v = 0; v < N; v++) {
//         if (seen[v]) {
//             continue;
//         }
//         dfs(G, v, seen, order);
//     }
//     reverse(order.begin(), order.end());
//     for (auto v : order) {
//         cout << v << "-> ";
//     }
//     cout << endl;
//     return 0;
// }

// サイクル検知
// - 与えられたグラフに対してサイクルが存在するかを判定する
// - サイクルのない無向グラフは木の集合なので「森」
// - サイクルのない有向グラフはDAG
// - 与えられたグラフにサイクルがあるとは「頂点vから出発した探索が，vから行くことのできる全頂点の探索を終えるよりも先に（つまり頂点vの帰りがけより前に）vに戻ってきてしまう」ということ
// - seen[v]: 行きがけの意味で頂点vに訪問済みかどうかを記録する
// - finished[v]: 帰りがけの意味で頂点vに訪問済みであるかどうかを記録する
// - seen[v] == true && finished[v] == falseのとき，そのグラフにサイクルが存在することが確定する
// - サイクルを復元するときには「行きがけ時にpushして帰りがけにpopするスタック」を用意することで得られる

// グラフ探索の考え方と動的計画法とは密接な関係にある．そもそも動的計画法とは，グラフ上の各辺を緩和する考え方が主軸になっている．DAGにおいてはDFS再帰関数の帰りがけにキャッシュにメモするだけでDPになる