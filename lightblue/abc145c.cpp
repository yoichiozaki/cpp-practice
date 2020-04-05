#include <bits/stdc++.h>
using namespace std;

int N;
double x[10], y[10];

double dist(int i, int j) {
  double dx = x[i] - x[j];
  double dy = y[i] - y[j];
  return pow(dx*dx + dy*dy, 0.5);
}

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> x[i] >> y[i];
  double sum = 0.0;
  vector<int> towns(N);
  for (int i = 0; i < N; i++) towns[i] = i+1;
  do {
    for (int i = 0; i < N-1; i++) {
      sum += dist(towns[i], towns[i+1]);
    }
  } while (next_permutation(towns.begin(), towns.end()));
  int fact = 1;
  for (int i = 2; i <= N; i++) fact *= i;
  cout << fixed << setprecision(12) << sum/fact << endl;
  return 0;
}