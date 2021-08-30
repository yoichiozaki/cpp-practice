#include <bits/stdc++.h>

using namespace std;

int sum_of_digits(int n)
{
    int sum = 0;
    while (0 < n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int sum = sum_of_digits(i);
        if (A <= sum && sum <= B)
            ans += i;
    }
    cout << ans << endl;
    return 0;
}