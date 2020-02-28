#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> score;
    score["Alice"] = 100;
    score["Bob"] = 89;
    score["Charlie"] = 95;
    cout << score.at("Alice") << endl;
    
    score["Dave"] = 10; // keyに対応するvalueが存在しない場合はvalueの型のゼロ値が追加される

    if (score.count("Alice")) {
        cout << "Alice: " << score.at("Alice") << endl;
    } else {
        cout << "No Alice" << endl;
    }

    cout << score.size() << endl;

    for (pair<string, int> p : score) {
        string key = p.first;
        int value = p.second;
        cout << key + ": " << value << endl;
    }

    for (auto p : svore) {
        auto key = p.first;
        auto value = p.second;
        cout << key + ": " << value << endl;
    }

    queue<int> q;
    q.push(10);
    q.push(1);
    q.push(2);
    cout << q.size() << endl;
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    priority_queue<int> pq;
    pq.push(10);
    pq.push(1);
    pq.push(5);
    pq.push(3);
    cout << pq.size() << endl;
    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    priority_queue<int, vector<int> greater<int>> rpq;
    rpq.push(10);
    rpq.push(2);
    rpq.push(5);
    cout << rpq.size() << endl;
    while (!rpq.empty()) {
        cout << rpq.top() << endl;
        rpq.pop();
    }

    set<int> S;
    S.insert(3);
    S.insert(7);
    S.insert(10);
    S.insert(3);
    S.erase(3);
    cout << S.size() << endl;

    if (S.count(7)) {
        cout << "found 7" << endl;
    }

    // 空の集合に適用してはだめ
    cout << S.*begin(S) << endl; // S内の最小値を取得
    cout << S.*rbegin(S) << endl; // S内の最大値を取得

    for (auto elem : S) {
        cout << elem << endl;
    }

    stack<int> s;
    s.push(10);
    s.push(1);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    sout << s.top() << endl;

    deque<int> d;
    d.push_back(10);
    d.push_back(1);
    d.push_back(3);
    cout << d.front() << endl;
    d.pop_front();
    cout << d.back() << endl;
    d.pop_back();
    d.push_front(5);
    d.push_back(2);
    count << d.at(1) << endl;

    // lower_bound() x以上の最小の要素
    // upper_bound() xを超える最小の要素
    
    vector<int> vec = {0, 10, 13, 14, 20};
    cout << *lower_bound(vec.begin(), vec.end(), 12) << endl; // 13
    cout << *lower_bound(vec.begin(), vec.end(), 14) << endl; // 14
    cout << *upper_bound(vec.begin(), vec.end(), 10) << endl; // 13

    // 空のqueueに対しての.front()とか空のsetに対する*variable.begin()とかは未定義動作
    // プログラム冒頭で #define _GLIBCXX_DEBUG とすると実行時エラーとして落ちる
}
