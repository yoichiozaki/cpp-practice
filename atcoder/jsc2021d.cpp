#include <iostream>
#include <atcoder/modint>
using namespace std;
using Modint = atcoder::modint1000000007;

int main()
{
    int N, P;
    cin >> N >> P;
    Modint p = P;
    Modint ans = (p - 1) * (p - 2).pow(N - 1);
    cout << ans.val() << endl;
}
