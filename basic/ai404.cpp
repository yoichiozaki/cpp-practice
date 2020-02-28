#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {3, 1, 5, 6, 7, 3, 4};

    auto iter1 = a.begin();
    iter1 = iter1 + 2;
    // adavnce(iter1, 2);
    auto iter2 = iter1 + 4;

    cout << *iter1 << endl;
    cout << *iter2 << endl;

    for (auto iter = a.begin(); it != a.end(); iter++) {
        cout << *iter << endl;
    }

    vector<pair<intm int>> a = {{1, 4}, {2, 5}, {3, 6}};
    auto iter = a.begin() + 1;
    cout << (iter->first) << ", " << (iter->second) << endl;

    // i番目の要素を指すイテレータ: next(コンテナ.begin(), i)
    // 末尾の要素を指すイテレータ: prev(コンテナ.end())
    // for (auto iter = コンテナ.begin(); iter != コンテナ.end; ) {
    //  if (要素を削除する条件) {
    //      iter = コンテナ.erase(iter); // eraseで引数に与えられるイテレータが無効化されてしまう点に注意
    //  } else {
    //      iter++;
    //  }
    // }

    // vectorのイテレータ
    // - 要素を削除するとその要素を含むそれ以降の要素に対するイテレータが無効化
    // - push_back等によってコンテナの容量が変更されるとすべての要素に対するイテレータが無効化
    // map/setのイテレータ
    // - 要素を削除するとその要素に対するイテレータが無効化
    // - map/setのイテレータは読み取り専用

    vector<int> a = {1, 2, 3, 5};
    auto iter = find(a.begin(), a.end(), 3);
    if (iter == a.end()) {
        cout << "not found" << endl;
    } else {
        int idx = distance(a.begin(), iter);
        cout << "a[" < idx << "] = " << *iter << endl;
    }

    vector<int> a = {1, 3, 4, 5, 9, 10};
    auto iter 
        = find_if(
                a.begin(), 
                a.end(), 
                [](int x) {
                    return (x % 2) == 0;
                }
        )
}
