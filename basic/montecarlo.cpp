#include <bits/stdc++.h>
using namespace std;

const int NUMBER_OF_SAMPLES = 1000000;

int main() {
     cout << fixed << setprecision(12);
    srand((unsigned)time(NULL));

    int cnt = 0;
    for (int i = 0; i < NUMBER_OF_SAMPLES; i++) {
        double px = 1.0 * (rand() % 32768 + 0.5) / 32768.0;
        double py = 1.0 * (rand() % 32768 + 0.5) / 32768.0;
        if (px*px + py*py <= 1) {
            cnt++;
        }
    }
    cout << 4.0 * cnt / NUMBER_OF_SAMPLES << endl;
}