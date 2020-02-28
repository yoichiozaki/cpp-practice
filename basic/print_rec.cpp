#include <bits/stdc++.h>
using namespace std;

string space(int num) 
{
    string ret = "";
    for (int i = 0; i < num; i++) {
        ret += " ";
    }
    return ret;
}

void print_in(int n, int depth)
{
    cout << space(depth * 4) << "-> func(" << n << ", " << depth << ")" << endl;
}

void print_out(int n, int depth)
{
    cout << space(depth * 4) << "<- func(" << n << ", " << depth << ")" << endl;
}

void func(int n, int depth) 
{
    if (n == 0) {
        print_in(n, depth);
        print_out(n, depth);
        return;
    }
    print_in(n, depth);
    func(n - 1, depth + 1);
    print_out(n, depth);
}

int main()
{
    func(3, 0);
}
