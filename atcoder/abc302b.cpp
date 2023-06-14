#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;

    int dx[8]={-1,-1,-1,0,0,1,1,1};
	int dy[8]={-1,0,1,-1,1,-1,0,1};

    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 8; k++) {
                string str = "";
                for (int t = 0; t < 5; t++) {
                    int x = i + t * dx[k], y = j + t * dy[k];
                    if ((x < 0) || (x >= N) || (y < 0) || (y >= M)) break;
                    str += S[x][y];
                }
                if (str == "snuke") {
                    for (int t = 0; t < 5; t++) {
                        int x = i + t * dx[k] + 1, y = j + t * dy[k] + 1;
                        cout << x << " " << y << endl; 
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}