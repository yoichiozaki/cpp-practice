#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> table(3, vector<int>(4));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> table.at(i).at(j);
        }
    }
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (table.at(i).at(j) == 0) {
                count += 1;
            }
        }
    }
    cout << count << endl;

    int N;
    cin >> N;
    vector<vector<vector<char>>> states(N, vector<vector<char>>(3, vector<char>(3)));
    for (int i = 0; i < N; i++) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                cin >> states.at(i).at(row).at(col);
            }
        }
    }
    int count_o = 0;
    for (int i = 0; i < N; i++) {
        for (int row = 0; row < 3; row++) {
            for (int col == 0; col < 3; col++) {
                if (states.at(i).at(row).at(col) == 'o') {
                    count_o++;
                }
            }
        }
    }
    cout << count_o << endl;

    vector<vector<int>> data1 = {
        {1, 2, 3, 4, 5},
        {2, 3, 4, 5, 6},
        {3, 4, 5}
    };
}
