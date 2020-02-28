#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
int number = 10;

int main()
{
    cout << (int)'A' << endl;
    cout << (int)'Z' << endl;
    cout << (char)65 << endl;
    cout << (char)90 << endl;
    // ASCII: 0-9, A-Z, a-zは連続していて大文字は小文字より小さい数値に対応している

    for (int i = 0; i <= ('Z' - 'A'); i++) {
        cout << (char)('A' + i) << endl;
    }
    // (char)'x' + ('A' - 'a') : 小文字 -> 大文字
    // (char)'X' - ('A' - 'a') : 大文字 -> 小文字
    // (char) toupper(文字)
    // (char) tolower(文字)

    char c = 'X';
    if ('A' <= c && c <= 'Z') {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    // 小文字判定: islower()
    // 数字判定: isdigit()
    
    const int a = 10; // 定数
    cout << a + 5 << endl;

    int a, b;
    cin >> a >> b;
    int answer = a < b ? a : b;
    cout << answer << endl;

    // ラムダ式
    auto my_min = [](int a, int b) {
        if (a < b) {
            return a;
        } else {
            return b;
        }
    };
    cout << my_min(4, 9) << endl;

    // ラムダ式の外の変数を使うときは[&]
    int max_num = 0;
    auto get_max = [&](int n) {
        if (max_num < n) {
            max_num = n;
        }
        return max_num;
    };
    cout << get_max(5) << endl;
    cout << get_max(2) << endl;

    // ラムダ式で再帰関数を書くときには型をautoではなくfunction<返り値の型(引数の型)>にする
    function<int(int)> sum = [&](int n) {
        if (n == 0) {
            return 0;
        }
        int s = sum(n - 1);
        return s + n;
    };
    cout << sum(10) << endl;

    vector<int> v = {2, 3, 1};
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

    vector<int> v = {2, 1, 3};
    sort(v.begin(), v.end());
    do {
        for (int x : v) {
            cout << x << " ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));

    cout << "hello, ";
    goto SKIP;
    cout << "world!" << endl;
SKIP:
    cout << "AtCoder!" << endl;
}
