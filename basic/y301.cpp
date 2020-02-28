#include <bits/stdc++.h>
using namespace std;

int main()
{
    // intで扱えるのはおおよそ2*10^9ぐらいまで
    int64_t a = 2000000000;
    int64_t b = a * 2;
    cout << b << endl;

    cout << 2000000000 * 2 << endl;
    cout << 2000000000LL * 2 << endl;

    // double型を標準出力に出すときcoutでは適当な桁で四捨五入される
    cout << 3.14159265358979 << endl;
    
    cout << fixed << setprecision(10); // 小数点以下10桁まで表示
    cout << 3.14159265358979 << endl;

    int a = 5;
    cout << (double)a << endl;

    double b = 3.141592;
    cout << (int)b << endl;

    // doubleの精度: doubleでは数字の列と小数点の位置を持っている
    // doble型の保持できる数字の列はだいたい16桁
    // 足す数それぞれをdubleの精度で扱えてもそれを足したあとの値が再現できない場合 => 情報落ち
    // なるべく小さい数から順に足し算していくことで情報落ちを防ぐ
    // 差の極端に小さい数同士を引き算すると値の精度が落ちる => 桁落ち
    // 引き算の際になるべくさを大きくするように順序を工夫したりそもそも引き算をなるべく行わないようにする工夫が必要
    
    int number = 100;
    string s = to_string(number);
    cout << s + "yen" << endl;

    string s = "100";
    int number = stoi(s);
    cout << number << endl;

    // size()で返ってくるのはsize_t(unsigned long)
    // 配列の長さ-1だけ繰り返すときとかは
    // for (int i = 0; i < (int)data.size() - 1; i++) {...}
    // ってやるとオーバーフローして死ぬのでintにキャストする
}
