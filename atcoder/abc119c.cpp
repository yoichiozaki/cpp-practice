#include <bits/stdc++.h>
using namespace std;

// 延長短縮合成魔法の順番は関係ない
// 「N個の竹のそれぞれがどの長さの竹の材料になるか」の組み合わせを先に決め打ってよい
// 「N個の竹のそれぞれがどの長さの竹の材料になるか」の組み合わせは全部で4^N通り
// 一度合成してしまってからそれぞれに対して長さをA,B,Cに揃えに行く

int N, A, B, C;
vector<int> l;

int rec(int i, int a, int b, int c)
{
    if (i == N)
    {
        if (min(a, min(b, c)) == 0)
            return 1001001; // N個の竹の割当が偏っていて無の竹ができてしまった
        return abs(a - A) + abs(b - B) + abs(c - C) - 30;
    }
    int ret0 = rec(i + 1, a, b, c);
    int ret1 = rec(i + 1, a + l[i], b, c) + 10;
    int ret2 = rec(i + 1, a, b + l[i], c) + 10;
    int ret3 = rec(i + 1, a, b, c + l[i]) + 10;
    return min(ret0, min(ret1, min(ret2, ret3)));
}

int main()
{
    cin >> N >> A >> B >> C;
    l.resize(N);
    for (int i = 0; i < N; i++)
        cin >> l[i];
    cout << rec(0, 0, 0, 0) << endl;
    return 0;
}