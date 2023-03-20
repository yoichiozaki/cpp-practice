#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, N, M, L; cin >> R >> N >> M >> L;
    vector<int> S(L);
    for (int i = 0; i < L; i++) cin >> S[i];
    
    int current_round = 0;
    int current_operation = 0;
    int remaining_pins = N;

    for (auto s : S) {
        if (s > remaining_pins) {
            cout << "No" << endl;
            return 0;
        }
        remaining_pins -= s;
        current_operation += 1;
        if (current_operation == M || remaining_pins == 0) {
            current_round += 1;
            current_operation = 0;
            remaining_pins = N;
        }
    }

    if (current_round == R && current_operation == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}