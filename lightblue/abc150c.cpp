#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) cin >> q[i];

  vector<int> s(n);
  for (int i = 0; i < n; i++) s[i] = i+1;
  int i = 0;
  int pidx = 0;
  int qidx = 0;
  do {
    bool pflag = true;
    for (int i = 0; i < n; i++) {
      if (s[i] != p[i]) pflag = false;
    }
    if (pflag) {
      pidx = i;
      break;
    } else i++;
  } while (next_permutation(s.begin(), s.end()));
  sort(s.begin(), s.end());
  i = 0;
  do {
    bool qflag = true;
    for (int i = 0; i < n; i++) {
      if (s[i] != q[i]) qflag = false;
    }
    if (qflag) {
      qidx = i;
      break;
    } else i++;
  } while (next_permutation(s.begin(), s.end()));

  cout << abs(pidx - qidx) << endl;
  return 0;
}