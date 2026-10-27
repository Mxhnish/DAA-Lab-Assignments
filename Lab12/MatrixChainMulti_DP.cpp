// Mohnish Dhankar
// 25/DA/044

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);

    cout << "Enter dimensions array: ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    vector<vector<long long>> dp(
        n + 1, vector<long long>(n + 1, 0)
    );

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++) {
                long long cost = dp[i][k]
                               + dp[k + 1][j]
                               + 1LL * p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    cout << "Minimum number of scalar multiplications: "
         << dp[1][n] << endl;

    return 0;
}