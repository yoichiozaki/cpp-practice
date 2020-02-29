#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
    cin >> n;
    vector<vector<vector<int>>> buildings(4, vector<vector<int>>(3, vector<int>(10, 0)));
    int b, f, r, v;
    for (int i = 0; i < n; i++) {
        cin >> b >> f >> r >> v;
        b -= 1; f -= 1; r -= 1;
        buildings.at(b).at(f).at(r) += v;
    }
    for (int bidx = 0; bidx < 4; bidx++) {
        for (int fidx = 0; fidx < 3; fidx++) {
            for (int ridx = 0; ridx < 10; ridx++) {
                cout << " " << buildings.at(bidx).at(fidx).at(ridx);
            }
            cout << endl;
        }
        if (bidx != 3) {
            cout << "####################" << endl;
        }
    }
    return 0;
}