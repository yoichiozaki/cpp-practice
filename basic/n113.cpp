#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    str = "abcd";
    cout << str.at(0) << endl;
    cout << str.size() << endl;

    vector<int> vec;
    vec = {25, 100, 64};
    cout << vec.at(0) << endl;
    cout << vec.size() << endl;

    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    cout << a1 + a2 + a3 << endl;

    vector<int> veca(3); // vector<type> name(size)
    cin >> veca.at(0) >> veca.at(1) >> veca.at(2);
    cout << veca.at(0) + veca.at(1) + veca.at(2) << endl;

    vector<int> vec1(100);
    for (int i = 0; i < 100; i++) {
        cin >> vec1.at(i);
    }

    int N;
    cin >> N;
    vector<int> math(N);
    vector<int> eng(N);
    for (int i = 0; i < N; i++) {
        cin >> math.at(i);
    }
    for (int i = 0; i < N; i++) {
        cin >> eng.at(i);
    }
    for (int i = 0; i < N; i++) {
        cout << math.at(i) + eng.at(i) << endl;
    }

    vector<int> vec2 = {1, 2, 3};
    vec2.push_back(10); // 後ろに要素を追加する
    vec2.pop_back(); // 後ろの要素を削除する

    vector<int> vec3(3, 5) // {5, 5, 5}

    vector<int> vec3 = {1, 2, 3};
    vector<int> vec4 = {1, 2, 3};
    if (vec3 == vec4) {
        cout << "OK" << endl;
    }
    // vectorを抱える変数同士は==で比較できる
    /*
    if (vec3 == {1, 2, 3)} {}
    とは書けない
    */
    vector<int> vec5(3, 10);
    vec5 = vector<int>(100, 2);
    cout << vec5.at(99) << endl;

}
