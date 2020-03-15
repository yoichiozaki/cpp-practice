#include <bits/stdc++.h>
using namespace std;

struct process {
    string name;
    int time;
};
using process = struct process;

const int LEN = 100005;

process Q[LEN];
int head, tail ,n;

void enqueue(process x) {
    Q[tail] = x;
    tail = (tail+1) % LEN;
}

process dequeue() {
    process x = Q[head];
    head = (head+1) % LEN;
    return x;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int main() {
    int elapse_time = 0, c;
    int i, q;
    process u;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> Q[i].name >> Q[i].time;
    }
    head = 1;
    tail = n+1;

    while (head != tail) {
        u = dequeue();
        c = min(q, u.time);
        u.time -= c;
        elapse_time += c;
        if (0 < u.time) enqueue(u);
        else cout << u.name << " " << elapse_time << endl;
    }
    return 0;
}