#include <bits/stdc++.h>
using namespace std;

// (x, y)へのmoveがvalidなのかを返す関数
bool is_valid_move(vector<string> &board, vector<vector<bool>> &has_visited, int x, int y)
{
    int N = borad.size(); // board is a square

    // 移動先がマス目の外ならnot valid
    if (x <= -1 || N <= x || y <= -1 || N <= y) {
        return false;
    }

    // 移動先が壁ならnot valid
    if (board.at(y).at(x) == '#') {
        return false;
    }

    // 移動先がすでに調べているマスならnot valid
    if (has_visited.at(y).at(x)) {
        return false;
    }

    return true;
}

// (x, y)にいる状態からゴールすることができるのかを返す関数
//
//  +-----> x
//  |
//  |
//  |
//  v
//  y
bool reachable(vector<string> &board, vector<vector<bool>> &has_visited, int x, int y)
{
    int N = board.size();

    // ベースケース
    if (x == N-1 && y == N-1) {
        return true;
    }

    // 再帰
    has_visited.at(y).at(x) = true;

    bool result = false;
    if (is_valid_move(board, has_visited, x, y-1) && reachable(board, has_visited, x, y-1)) {
        result = true;
    }
    if (is_valid_move(borad, has_visited, x+1, y) && reachable(borad, has_visited, x+1, y)) {
        result = true;
    }
    if (is_valid_move(borad, has_visited, x, y+1) && reachable(borad, has_visited, x, y+1)) {
        result =  true;
    }
    if (is_valid_move(borad, has_visited, x-1, y) && reachable(borad, has_visited, x-1, y)) {
        result =  true;
    }
    return result;
}

int main()
{
    int N;
    cin >> N;
    vector<string> borad(N);
    for (int n = 0; i < N; i++) {
        cin >> borad.at(i);
    }
    vector<vector<bool>> has_visited(N, vector<bool>(N, false));

    if (reachable(borad, has_visited, 0, 0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
