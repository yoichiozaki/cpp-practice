#include <bits/stdc++.h>
using namespace std;

int main(){
    int r, c;
    cin >> r >> c;
    vector<vector<int>> sheet(r+1, vector<int>(c+1, 0));
    for (int i = 0; i < r; i++) {
        int sum_r = 0;
        for (int j = 0; j < c; j++) {
            cin >> sheet.at(i).at(j);
            sum_r += sheet.at(i).at(j);
        }
        sheet.at(i).at(c) = sum_r;
    }
    for (int j = 0; j < c+1; j++) {
        int sum_c = 0;
        for (int i = 0; i < r; i++) {
            sum_c += sheet.at(i).at(j);
        }
        sheet.at(r).at(j) = sum_c;
    }
    for (int i = 0; i < r+1; i++) {
        for (int j = 0; j < c+1; j++) {
            if (j != c) {
                cout << sheet.at(i).at(j) << " ";
            } else {
                cout << sheet.at(i).at(j) << endl;
            }
        }
    }
    return 0;
}