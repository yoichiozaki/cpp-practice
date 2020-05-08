#include <bits/stdc++.h>
using namespace std;

const int M = 2;

void DFS(vector<int> &A)
{
    if (A.size() == 10) // Aの長さが10に達したらそこで探索から返る（末端）
    {
        // 配列Aに施したい処理をここに書く
        for (int i = 0; i < 10; i++)
            cout << A[i];
        cout << endl;
        return;
    }

    for (int v = 0; v < M; v++)
    {
        A.push_back(v);
        DFS(A);
        A.pop_back();
    }
}

int main()
{
    vector<int> A;
    DFS(A);
    return 0;
}