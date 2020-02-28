#include <bits/stdc++.h>
using namespace std;

/* 再帰関数
 * 「ある関数内で自分自身を呼び出す」ことを再帰呼び出しという
 * 再帰呼び出しを行わずに完了できる処理をベースケースという
 * 再帰呼び出しを行い，その結果を用いて行う処理のことを再帰ステップという
 * 再帰関数の実装は3ステップ
 *   1. 「引数」「返り値」「処理内容」を決める
 *   2. 再帰ステップの実装
 *   3. ベースケースの実装
 * 再帰関数が正しく動作するためには「再帰呼出しの連鎖に終わりがある = 再帰ステップでの再帰呼び出しを繰り返すうちに必ずベースケースに到達する」という条件を満たす必要がある
 */

int sum(int n)
{
    if (n == 0) {
        return 0;
    }

    int s = sum(n - 1);
    return s + n;
}

int sum_range(int a, int b)
{
    if (a == b) {
        return a;
    }

    int s = sum_range(a, b-1);
    return s + b
}

int array_sum_from_i(vector<int> &data, int i)
{
    if (i == data.size()) {
        return 0;
    }

    int s = array_sum_from_i(data, i + 1);
    return data.at(i) + s;
}

int array_sum(vector<int> &data)
{
    return array_sum_from_i(data, 0);
}

bool has_divisor(int N, int i)
{
    if (i == N) {
        return false;
    }

    if (N % i == 0) {
        return true;
    }

    return has_divisor(N, i + 1);
}

bool is_prime(int N)
{
    if (N == 1) {
        return false;
    } else if (N == 2) {
        return true;
    } else {
        return !has_divisor(N, 2);
    }
}

vector<int> reverse_array_from_i(vector<int> &data, int i)
{
    if (i == data.size()) {
        vector<int> empty_array(0);
        return empty_array;
    }

    vector<int> tmp = reverse_array_from_i(data, i + 1);
    tmp.push_back(data.at(i));
    return tmp;
}

vector<int> reverse_array(vector<int> &data) {
    return reverse_array_from_i(data, 0);
}

int main()
{
    cout << sum(10) << endl;
}
