#include <bits/stdc++.h>
using namespace std;

struct MyPair {
    int x;
    string y;

    MyPair()
    {
        cout << "constructor called" << endl;
    }
    // 複数コンストラクタか定義可能
    // 構造体名 オブジェクト名 = {コンストラクタの引数, ...} <- メンバ変数ではない点に注意
    MyPair(int x_) {
        x = x_;
    }
    MyPair(int x_, string s_) {
        x = x_;
        s = s_;
    }
    // コピーコンストラクタ: 関数の引数としてオブジェクトを渡した場合など
    // MyPoint(const MyPoint &old) {
    //  初期化など
    // }
    // constとすることでコピー元となるオブジェクトをread-onlyにしている
    // コピーコンストラクタを定義しない場合は「全てのメンバ変数をそのままコピーして新しいオブジェクトを作る」コピーコンストラクタが自動的に作られる

    void print()
    {
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
    }

    // オペレータのオーバーロード
    MyPair operator+(const MyPair &other) {
        MyPair ret;
        ret.x = x + other.x;
        ret.y = y + other.y;
        return ret;
    }
    MyPair operator=(const MyPair &other) {
        cout << "= operator called" << endl;
        x = other.x;
        y = other.y;
    }
};

// 構造体定義の外側でも演算子のオーバーロードが可能
// 複合演算子（+= -= など）は不可能
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
    pair<int, int> ret;
    ret.first = a.first + b.first;
    ret.second = a.second + b.second;
    return ret;
}

bool operator<(pair<int, int> l, pair<int, int> r) {
    if (l.second != r.second) {
        return l.second < r.second;
    } else {
        return l.first < r.first;
    }
}

bool operator>(pair<int, int> l, pair<int, int> r) {
    return r < l;
}
bool operator<=(pair<int, int> l, pair<int, int> r) {
    return !(r < l);
}
bool operator>=(pair<int, int> l, pair<int, int> r) {
    return !(l < r);
}

// STLのコンテナの要素として自分の定義した構造体を用いる場合は特定の演算子をオーバーロードする必要があることがある
// bool operator<(const structure_name &left, const structure_name &right) {
//  ...
// }

struct NumString {
    int length;
    string s;

    NumString(int num) {
        cout << "constructor called" << endl;
        s = to_string(num);
        length = s.size();
    }
}

int main()
{
    MyPair p = {12345, "hello"};
    cout << "p.x: " << p.x << endl;
    cout << "p.y: " << p.y << endl;

    // 構造体の辺数宣言
    // 構造体名 変数名;
    // auto 変数名 = 構造体名();
    
    p.print();

    NumString num(12345);
    cout << "num.s: " << num.s << endl;
    cout << "num.length: " << num.length << endl;
}

// 初期化子リスト: コンストラクタ内でメンバ変数に代入できない場合に使う（メンバ引数が参照型だったりしたとき）
// struct MyPair {
//  int x;
//  string y;
//  MyPair() : x(123), y("hogehoge") {}
// };

// 構造体とクラスの違い
// メンバ変数・メンバ関数へのデフォルトのアクセス制御が大きな違い
// 構造体はpublicがデフォルト
// クラスはprivateがデフォルト
// c++では継承もできる
