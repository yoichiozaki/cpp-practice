#include <bits/stdc++.h>
using namespace std;

int main(){
  long double P;
  cin >> P;
  if(P < 1.5/log(2.0)){
    cout << fixed << setprecision(10);
    cout << P << endl;
    return 0;
  }
  long double t = 1.5 + 1.5 * log(P * log(2.0) / 3.0) / log(2.0);
  long double ans = (long double)(1.5 / log(2)) + t;
  cout << fixed << setprecision(10);
  cout << ans << endl;
}
