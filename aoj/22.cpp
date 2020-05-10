#include <bits/stdc++.h>
using namespace std;

// Maximum sum subarray problem: https://en.wikipedia.org/wiki/Maximum_subarray_problem
//
// i = 1 ... jに対して
// dp[j] = 「A[i] + A[i+1] + .. A[j-1] + A[j]」の最大値
// とすると，
// dp[1] = max(A[1], 0)          : A[1] < 0の場合はA[1]を和に含めない
// dp[j] = max(dp[j-1] + A[j], 0): A[j] < 0の場合はA[j]を和に含めない
// dp[j]の更新に直前の値dp[j-1]しか使わないので，dpテーブルは省略して1つの変数にできる
//
// def max_subarray(numbers):
//     best_sum = 0
//     current_sum = 0
//     for x in numbers:
//         current_sum = max(0, current_sum + x)
//         best_sum = max(best_sum, current_sum)
//     return best_sum
//
// def max_subarray(numbers):
//     best_sum = 0
//     best_start = best_end = 0
//     current_sum = 0
//     for current_end, x in enumerate(numbers):
//         if current_sum <= 0:
//             current_start = current_end
//             current_sum = x
//         else:
//             current_sum += x
//         if best_sum < current_sum:
//             best_sum = current_sum
//             best_start = current_start
//             best_end = current_end + 1
//     return best_sum, best_start, best_end

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long best_sum = 1 << 20;
        best_sum *= -1LL;
        long long current_sum = 0;
        for (int i = 0; i < n; i++)
        {
            current_sum = max(0LL, current_sum + a[i]);
            best_sum = max(best_sum, current_sum);
        }
        cout << best_sum << endl;
    }
    return 0;
}