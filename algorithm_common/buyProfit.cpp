//
// Created by 12582 on 2025/1/7.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int maxProfit = 0;
        vector<vector<int>> dp(n, vector<int>(5, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = -prices[0];
        dp[0][4] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        maxProfit = max(dp[n - 1][0], max(dp[n - 1][2], dp[n - 1][4]));
        return maxProfit;
    }
};

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
    return 0;
}
