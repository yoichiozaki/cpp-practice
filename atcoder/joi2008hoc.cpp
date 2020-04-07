#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; long long M; cin >> N >> M;
  vector<long long> P(N);
  for (int i = 0; i < N; i++) cin >> P[i];
  P.push_back(0LL);
  N += 1;

  vector<long long> Q;
  set<long long> tmp;
  for (int i = 0; i < N+1; i++) {
    for (int j = i; j < N+1; j++) {
      tmp.insert(P[i] + P[j]);
    }
  }
  for (auto iter = tmp.begin(); iter != tmp.end(); iter++) Q.push_back(*iter);
  sort(Q.begin(), Q.end());

  long long ans = -1;
  for (int i = 0; i < (int)Q.size(); i++) {
    long long total = Q[i];
    if (M < total) break;
    int ok = -1;
    int ng = (int)Q.size();
    while (1 < abs(ok - ng)) {
      int mid = (ok + ng) / 2;
      bool is_ok = true;
      if (M < total + Q[mid]) is_ok = false;
      if (is_ok) ok = mid;
      else ng = mid;
    }
    total += Q[ok];
    ans = max(ans, total);
  }
  cout << ans << endl;
  return 0;
}