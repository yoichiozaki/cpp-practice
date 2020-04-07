#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll N;
ll H[100010], S[100010];

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> H[i] >> S[i];
  ll ng = 0;
  ll ok = 1e15;
  vector<ll> hist(N); // hist[i]: 時刻iまでに割らなければならない風船の個数
  while (1 < abs(ok - ng)) {
    ll mid = (ok + ng) / 2;
    bool flag = true;

    // 以下でbool is_ok(mid){...}を計算
    for (int i = 0; i < N; i++) hist[i] = 0;
    for (int i = 0; i < N; i++) {
      if (mid < H[i]) flag = false; // 時刻0ですでに高度midより上に風船がある
      ll remind_time = (mid - H[i]) / S[i]; // 高度midに到達するまでの時間的猶予
      if (remind_time < 0) {
        flag = false;
        break;
      }
      hist[min(remind_time, N-1)]++;
    }
    for (int i = 1; i < N; i++) hist[i] += hist[i-1];
    for (int i = 0; i < N; i++) {
      if (i+1 < hist[i]) flag = false; // 時刻iまでに割れる最大の風船の個数はi+1個（時刻0のときに1つ割ることに注意）
    }

    if (flag) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}