class Solution {
public:
    int recursion(vector<int>& coins, int amount, int i,
                  vector<vector<int>>& dp) {
        if (amount == 0) {
            return 0;
        }

        if (i >= coins.size()) {
            return INT_MAX;
        }

        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        int take = INT_MAX;
        if (coins[i] <= amount) {
            int res = recursion(coins, amount - coins[i], i, dp);
            if (res != INT_MAX) {
                take = res + 1;
            }
        }

        int skip = recursion(coins, amount, i + 1, dp);

        return dp[i][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = recursion(coins, amount, 0, dp);

        return ans == INT_MAX ? -1 : ans;
    }
};
