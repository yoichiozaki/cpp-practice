#include <bits/stdc++.h>
using namespace std;

// 関数のテンプレート
template <typename T>
T square(T x) {
    return x * x;
}

// 構造体のテンプレート
template <typename T>
struct Point {
    T x;
    T y;
    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// 定数のテンプレート
// 関数内で用いる定数のテンプレート
template <int INDEX1, int INDEX2>
void tuple_swap(tuple<int, int, int> &x) {
    swap(get<INDEX1>(x), get<INDEX2>(x));
}
// 構造体内で用いる定数のテンプレート
template <int MOD>
struct Modulo {
    int x;
    Modulo() {}
    Modulo(int v) {
        x = v % MOD;
    }
    Modulo plus(Modulo<MOD> other) {
        Modulo<MOD> result;
        result.x = (x + other.x) % MOD;
        return result;
    }
};

// 競技プログラミングでよく用いられるテンプレート
template <typename T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int f(int n) {
    return n * n - 8 * n + 3;
}

int main() {
    int a = 3;
    double b = 1.2;

    cout << square<int>(a) << endl;
    cout << square<double>(b) << endl;

    Point<int> p1= {0, 1};
    p1.print();
    Point<double> p2 = {2.3, 4.5};
    p2.print();

    Modulo<10> a(7), b(5);
    auto c = a.plus(b);
    cout << c.x << endl;

    int ans_min = 1000000000;
    int ans_max = 0;
    for (int i = 1; i <= 10; i++) {
        chmin<int>(ans_min, f(i));
        chmax<int>(ans_max, f(i));
    }
    cout << ans_min << ", " << ans_max << endl;
}
