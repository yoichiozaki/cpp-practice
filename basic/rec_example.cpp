#include <bits/stdc++.h>
using namespace std;

// すべての組織における親子関係を表すテーブルを参照渡しでchildrenとして受け取り，
// 組織xにおける「子組織からの報告書が揃う時刻」を返す関数
int complete_time(vector<vector<int>> &children, int x)
{
    // ベースケース
    if (children.at(x).size() == 0) {
        return 0;
    }

    // 再帰
    int max_receive_time = 0;
    for (int c : children.at(x)) {
        int receive_time = complete_time(children, c) + 1;
        max_receive_time = max(max_receive_time, receive_time);
    }
    return max_receive_time;
}

int main()
{
    int N;
    cin >> N;

    vector<int> p(N); // 各組織の親組織へのポインタを格納するvector<int>
    p.at(0) = -1;
    for (int i = 1; i < N; i++) {
        cin >> p.at(i);
    }

    vector<vector<int>> children(N); // 各組織の子組織一覧を格納するvector<vector<int>>
    for (int i = 1; i < N; i++) {
        int parent = p.at(i);
        children.at(parent).push_back(i);
    }

    cout << complete_time(children, 0) << endl;

}
