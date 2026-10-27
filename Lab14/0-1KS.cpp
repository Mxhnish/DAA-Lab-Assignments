// Mohnish Dhankar
// 25/DA/044

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n), value(n);

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<vector<int>> dp(
        n + 1, vector<int>(W + 1, 0)
    );

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            dp[i][w] = dp[i - 1][w];

            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i][w],
                    value[i - 1]
                    + dp[i - 1][w - weight[i - 1]]
                );
            }
        }
    }

    cout << "Maximum value: " << dp[n][W] << endl;

    cout << "Selected item numbers: ";
    int w = W;

    for (int i = n; i >= 1; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i << " ";
            w -= weight[i - 1];
        }
    }

    cout << endl;

    return 0;
}