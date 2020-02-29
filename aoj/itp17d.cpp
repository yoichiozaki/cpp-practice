#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n, m, l;
    cin >> n >> m >> l;
    vector<vector<ll>> a(n, vector<ll>(m, 0));
    vector<vector<ll>> b(m, vector<ll>(l, 0));
    vector<vector<ll>> c(n, vector<ll>(l, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a.at(i).at(j);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            cin >> b.at(i).at(j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < m; k++) {
                c.at(i).at(j) += a.at(i).at(k) * b.at(k).at(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            if (j != l-1) {
                cout << c.at(i).at(j) << " ";
            } else {
                cout << c.at(i).at(j) << endl;
            }
        }
    }
    return 0;
}