#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<int> b(m, 0);
    vector<int> c(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a.at(i).at(j);
        }
    }
    for (int j = 0; j < m; j++) {
        cin >> b.at(j);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c.at(i) += a.at(i).at(j)*b.at(j);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << c.at(i) << endl;
    }
    return 0;
}