//
// Created by 12582 on 2025/1/7.
//

#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <array>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <bitset>
#include <cassert>
#include <random>
#include <sstream>
#include <iomanip>
#include <functional>
#include <chrono>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0) return 0;
        int n = prices.size();
        if (k > n / 2) k = n / 2;

        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for (int i = 1; i <= k; ++i) {
            int max_profit_so_far = INT_MIN;
            for (int j = 1; j < n; ++j) {
                max_profit_so_far = max(max_profit_so_far, dp[i - 1][j - 1] - prices[j - 1]);
                dp[i][j] = max(dp[i][j - 1], max_profit_so_far + prices[j]);
            }
        }
        return dp[k][n - 1];
    }
};


int main() {

    return 0;
}
