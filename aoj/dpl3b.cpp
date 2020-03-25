#include <bits/stdc++.h>
using namespace std;

#define MAX 1400

struct Rectangle {
    int height;
    int pos;
};

int solution(int size, int buffer[]) {
    stack<Rectangle> S;
    int maxv = 0;
    buffer[size] = 0;

    for (int i = 0; i <= size; i++) {
        Rectangle rect;
        rect.height = buffer[i];
        rect.pos = i;
        if (S.empty()) {
            S.push(rect);
        } else {
            if (S.top().height < rect.height) {
                S.push(rect);
            } else if (rect.height < S.top().height) {
                int target = i;
                while (!S.empty() && rect.height <= S.top().height) {
                    Rectangle pre = S.top(); S.pop();
                    int area = pre.height * (i - pre.pos);
                    maxv = max(maxv, area);
                    target = pre.pos;
                }
                rect.pos = target;
                S.push(rect);
            }
        }
    }
    return maxv;
}

int H, W;
int buffer[MAX][MAX];
int T[MAX][MAX];

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> buffer[i][j];
        }
    }
    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H; i++) {
            if (buffer[i][j]) {
                T[i][j] = 0;
            } else {
                T[i][j] = (0 < i) ? T[i-1][j]+1 : 1;
            }
        }
    }
    int maxv = 0;
    for (int i = 0; i < H; i++) {
        maxv = max(maxv, solution(W, T[i]));
    }
    cout << maxv << endl;
    return 0;
}